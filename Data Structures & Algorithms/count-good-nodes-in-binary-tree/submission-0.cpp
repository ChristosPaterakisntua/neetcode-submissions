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
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root, root->val, res);
        return res;
    }
private:
    void dfs(TreeNode* t, int comp, int &res) {
        if (!t) return;
        if (t->val >= comp) {
            ++res;
            dfs(t->right, t->val, res);
            dfs(t->left, t->val, res);
        }
        else {
            dfs(t->right, comp, res);
            dfs(t->left, comp, res);
        }
        
    }
};
