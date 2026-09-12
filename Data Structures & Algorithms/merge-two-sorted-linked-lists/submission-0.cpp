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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *l1 = list1, *l2 = list2, *prev = nullptr, *head= nullptr;
        while (l1 != nullptr && l2 != nullptr) {
            ListNode* block = new ListNode;
            if (l1->val < l2->val) {
                block->val = l1->val;
                l1 = l1->next;
            }
            else {
                block->val = l2->val;
                l2 = l2->next;
            }
            if (prev) {
                prev->next = block;
                prev = block;
            }
            else {
                prev = block;
                head = prev;
            }
        }
        while (l1) {
            ListNode* block = new ListNode;
            block->val = l1->val;
            if (prev) {
                prev->next = block;
                prev = block;
            }
            else {
                prev = block;
                head = prev;
            }
            l1 = l1->next;
        }
        while (l2) {
            ListNode* block = new ListNode;
            block->val = l2->val;
            if (prev) {
                prev->next = block;
                prev = block;
            }
            else {
                prev = block;
                head = prev;
            }
            l2 = l2->next;
        }
        return head;
    }
};
