/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    struct pair
    {
        ListNode* head;
        ListNode* tail;
    };
public:
    
    pair rev(ListNode* head)
    {
        if (head == NULL || head->next == NULL)     //if list has a single or no element
        {
            pair ans ;
            ans.head = head;
            ans.tail = head;
            return ans;
        }
        
        pair smallans;          
        smallans = rev(head -> next);
        smallans.tail->next = head;                 //small ans is sent itno rec calls
        head->next = NULL;                          //tail ka next is made head, n head ka next is NULL
        
        pair ans ;
        ans.head = smallans.head;
        ans.tail = smallans.tail -> next;           //update tail before returning
        return ans;
    }
    
    ListNode* reverseList(ListNode* head) {
        return rev(head).head;  //we call a recursive fx which maintains head and tail both
    }
};
