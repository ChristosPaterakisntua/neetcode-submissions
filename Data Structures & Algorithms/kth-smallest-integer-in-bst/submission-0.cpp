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
        int res;
        dfs(root, k, res);
        return res;
    }
private:
    void dfs(TreeNode* t, int &k, int &res) {
        if (!t) return;
        dfs(t->left, k, res);
        --k;
        if (!k) {
            res = t->val;
            return;
        }
        dfs(t->right, k, res);
    }
};
