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
        ListNode* root = nullptr;
        ListNode* top = root;
        while (list1 && list2) {
            ListNode* block = new ListNode;
            if (list1->val < list2->val) {
                block->val = list1->val;
                list1 = list1->next;
            }
            else {
                block->val = list2->val;
                list2 = list2->next;
            }
            if (root) {
                top->next = block;
                top = top->next;
            }
            else {
                root = block;
                top = root;
            }
        }
        while (list1) {
            ListNode* block = new ListNode(list1->val);
            list1 = list1->next;
            if (root) {
                top->next = block;
                top = top->next;
            }
            else {
                root = block;
                top = root;
            }
        }
        while (list2) {
            ListNode* block = new ListNode(list2->val);
            list2 = list2->next;
            if (root) {
                top->next = block;
                top = top->next;
            }
            else {
                root = block;
                top = root;
            }
        }
        return root;
    }
};
