

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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (head == NULL)
        {
            return head;
        }
        ListNode* previous = head;
        ListNode* temp = head->next;
        ListNode* X;
        while( temp!= NULL)
        {
            if(temp->val == previous->val)
            {
                X = temp;
                if (X->next !=NULL)
                {
                    X = temp;
                    previous -> next = X->next;
                    temp = temp->next;
                }
                else
                {
                    previous -> next = NULL;
                    return head;
                }
                
            }
            else
            {
                previous = previous->next;
                temp = temp -> next;
            }
        }
        return head;
        
    }
};
