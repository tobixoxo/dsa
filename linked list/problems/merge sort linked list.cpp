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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* t, *c1, *c2, *ans;
        if (l1 == NULL && l2 == NULL) return l1;
        else if (l1 == NULL) return l2;
        else if ( l2 == NULL) return l1;
        
        if ( l1->val < l2->val)
        {
            c2 = l1;
            c1 = l2;
        }
        else
        {
            c2 = l2;
            c1 = l1;
        }
        t = c2 -> next;
        ans = c2;
        
        if ( c2-> next == NULL )
        {
            c2 ->next = c1;
            return c2;
        }
        
        
        while(t != NULL && c1 != NULL)
        {
            if ( c1->val < t-> val)
            {
                c2->next = c1;
                c2 = c2->next;
                c1=  c1-> next;
            }
            else
            {
                c2->next = t;
                t = t-> next;
                c2 = c2 -> next;
            }
            
        }
        if ( t == NULL) c2->next = c1;
        else if (c1 == NULL ) c2->next = t;
        
        return ans;
    }
    
    ListNode* sortList(ListNode* head) {
        if (head== NULL)
        {
            return NULL;
        }
        if (head->next == NULL)
        {
            return head;
        }
        else
        {
            ListNode* fast = head->next;
            ListNode* slow = head;
            while(fast != NULL && fast->next != NULL)
            {
                slow = slow ->next;
                fast = fast ->next ->next;
            }
            //slow is mid of the list
            ListNode* mid = slow ->next;
            slow->next = NULL;
            head = mergeTwoLists(sortList(head), sortList(mid));
            return head;
        }
        
        
        
    }
};
