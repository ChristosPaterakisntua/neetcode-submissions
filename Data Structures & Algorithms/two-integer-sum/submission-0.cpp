class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> first;
        first[nums[0]] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (first.find(diff) != first.end()) {
                return {first[diff], i};
            }
            first[nums[i]] = i;
        }
        return {};
    }
};
