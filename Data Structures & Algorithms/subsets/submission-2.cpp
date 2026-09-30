class Solution {
private:
    void backtrack(vector<int>& cur_path, int i, vector<int>& nums, vector<vector<int>>& paths) {
        // base
        if (i == (int)nums.size()) {
            paths.push_back(cur_path);
            return;
        }

        // include
        cur_path.push_back(nums[i]);
        backtrack(cur_path, i+1, nums, paths);

        // exclude
        cur_path.pop_back();
        backtrack(cur_path, i+1, nums, paths);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.reserve(pow(2, (int)nums.size()));
        vector<int> cur_path;
        backtrack(cur_path, 0, nums, res);
        return res;
    }
};
