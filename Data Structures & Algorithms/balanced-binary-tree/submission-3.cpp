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
    bool isBalanced(TreeNode* root) {
        bool res = true;
        dfs(root, res);
        return res;
    }
private:
    int dfs(TreeNode* t, bool &res) {
        if (!t) return 0;
        int hl = dfs(t->left, res);
        int hr = dfs(t->right, res);
        if (abs(hr - hl) > 1) res = false;
        return 1 + max(hr, hl);
    }
};
