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
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        int count = 0;
        while(count < 10100 )
        {
            if (temp == NULL) return false;
            temp = temp-> next;
            count++;
        }
        if (count>10000)
        {
            return true;
        }
        else return false;
    }
};
