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
    bool isValidBST(TreeNode* root) {
        return dfs(root, -INT_MAX, INT_MAX);
    }
private:
    bool dfs(TreeNode* t, int lowerb, int upperb) {
        if (!t) return true;
        if (t->val <= lowerb || t->val >= upperb) return false;
        return dfs(t->left, lowerb, t->val) && dfs(t->right, t->val, upperb);
    }
};
