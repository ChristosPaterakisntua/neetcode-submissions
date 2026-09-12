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
        while (l1 && l2) {
            sum = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            ListNode* block = new ListNode(sum);
            if (tmp) tmp->next = block;
            else head = block;
            tmp = block;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            sum = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            ListNode* block = new ListNode(sum);
            if (tmp) tmp->next = block;
            else head = block;
            tmp = block;
            l1 = l1->next;
        }
        while (l2) {
            sum = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            ListNode* block = new ListNode(sum);
            if (tmp) tmp->next = block;
            else head = block;
            tmp = block;
            l2 = l2->next;
        }
        if (carry) {
            ListNode* block = new ListNode(carry);
            tmp->next = block;
        }
        return head;
    }
};
