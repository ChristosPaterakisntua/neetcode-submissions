/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inord_arr;
        inorder(root, inord_arr);
        return inord_arr[k-1];
    }
private:
    void inorder(TreeNode* t, vector<int> &inord_arr) {
        if (!t) return;
        inorder(t->left, inord_arr);
        inord_arr.push_back(t->val);
        inorder(t->right, inord_arr);
    }
};
