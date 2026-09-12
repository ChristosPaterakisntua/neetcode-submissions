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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        ListNode* prev = nullptr;
        while (p) {
            ListNode* block = new ListNode;
            block->val = p->val;
            block->next = prev;
            prev = block;
            p = p->next;
        }
        return prev;
    }
};
