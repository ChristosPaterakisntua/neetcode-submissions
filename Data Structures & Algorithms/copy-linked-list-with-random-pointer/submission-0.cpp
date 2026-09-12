/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> copies;
    
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        if (copies.count(head)) return copies[head];
        Node* block = new Node(head->val);
        copies[head] = block;
        block->next = copyRandomList(head->next);
        block->random = copies[head->random];
        return block;       
    }
};
