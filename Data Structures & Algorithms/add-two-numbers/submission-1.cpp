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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum;
        int carry = 0;
        ListNode* tmp = nullptr;
        ListNode* head = nullptr;
        while (l1 || l2) {
            int v1 = (l1) ? l1->val : 0;
            int v2 = (l2) ? l2->val : 0;
            sum = (v1 + v2 + carry) % 10;
            carry = (v1 + v2 + carry) / 10;
            ListNode* block = new ListNode(sum);
            if (tmp) tmp->next = block;
            else head = block;
            tmp = block;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) {
            ListNode* block = new ListNode(carry);
            tmp->next = block;
        }
        return head;
    }
};
