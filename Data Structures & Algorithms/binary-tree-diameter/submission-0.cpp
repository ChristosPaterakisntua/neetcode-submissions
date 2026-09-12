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
    int height(TreeNode* t) {
        if (!t) return 0;
        return 1 + max(height(t->right), height(t->left));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int diameter = height(root->right) + height(root->left);
        int local = max(diameterOfBinaryTree(root->right), 
                        diameterOfBinaryTree(root->left));
        return max(local, diameter);
    }
};
