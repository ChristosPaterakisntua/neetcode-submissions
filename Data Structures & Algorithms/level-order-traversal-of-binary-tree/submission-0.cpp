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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        return res;
    }
private:
    void dfs(TreeNode* t, int level, vector<vector<int>> &res) {
        if (!t) return;
        if (res.size() == level) res.push_back(vector<int>());
        res[level].push_back(t->val);
        dfs(t->left, level+1, res);
        dfs(t->right, level+1, res);
    }
};
