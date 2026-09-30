class Solution {
private:
    void backtrack( 
        int i,
        vector<int> & cur_path,
        const vector<int> & nums,
        int target,
        vector<vector<int>> & sums
    ) {
        if (!target) {
            sums.push_back(cur_path);
            return;
        }

        if (target < 0 || i == (int)nums.size()) {
            return;
        }
        
        // include but don't change level
        cur_path.push_back(nums[i]);
        backtrack(i, cur_path, nums, target - nums[i], sums);
        // exclude
        cur_path.pop_back();
        backtrack(i+1, cur_path, nums, target, sums);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> cur_path;
        backtrack(0, cur_path, nums, target, res);
        return res;
    }
};
