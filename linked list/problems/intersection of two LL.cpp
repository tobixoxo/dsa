/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        
        /*
        if(headA == headB)
        {
            return headA;
        }
        */
        ListNode* t2 = headA;
        while(t2!= NULL)
        {
            ListNode* t1 = headB;
            while(t1 != NULL)
            {
                if (t1 == t2) 
                {
                    return t1;
                }
                else t1 = t1->next;
            }
            t2 = t2->next;
        }
        return NULL;
        
    }
};
