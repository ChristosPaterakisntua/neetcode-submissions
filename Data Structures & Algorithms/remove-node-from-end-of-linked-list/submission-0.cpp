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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        int len = 0;
        while (p) {
            ++len;
            p = p->next;
        }
        if (n == len) {
            ListNode* q = head;
            head = head->next;
            delete q;
            return head;
        }
        p = head;
        for (int i = 0; i < len - n - 1; ++i) p = p->next;
        ListNode* toDel = p->next;
        p->next = toDel->next;
        delete toDel;
        return head;
    }
};
