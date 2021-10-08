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
public:
    int length(ListNode* head)
    {
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL)
        {
            len++;
            temp= temp->next;
        }
        return len;
    }
    
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;                        //idea is to place slow at middle, when fast reaches at the end
        int len = length(head);
        while(fast != NULL && fast ->next != NULL)    
        {
            slow = slow->next;
            fast = fast->next ->next;
        }
        if (fast == NULL) return slow;
        else if (fast->next == NULL) return slow->next;
        return slow ;
        
    }
};
