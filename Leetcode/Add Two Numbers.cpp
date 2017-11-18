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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *suru = ans;
        int rem = 0;
        while(l1 != NULL || l2 != NULL)
        {
            if(l1 != NULL) rem += l1->val,l1 = l1->next;
            if(l2 != NULL) rem += l2->val,l2 = l2->next;
            int val = rem % 10;
            rem /= 10;
            ans->next = new ListNode(val);
            ans = ans->next;
        }
        if(rem)ans -> next = new ListNode(rem);
        return suru->next;

    }
};
