class Solution {
private:
    void backtrack(
        vector<int> & cur_perm,
        vector<vector<int>> & perms,
        vector<int> & used,
        const vector<int> & nums
    ) {
        if (cur_perm.size() == nums.size()) {
            perms.push_back(cur_perm);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (!used[i]) {
                cur_perm.push_back(nums[i]);
                used[i] = 1;
                backtrack(cur_perm, perms, used, nums);

                cur_perm.pop_back();
                used[i] = 0;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        vector<int> cur_perm;
        vector<int> used(nums.size(), 0);
        backtrack(cur_perm, perms, used, nums);
        return perms;
    }
};
