class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            if (seen[nums[i]]) return nums[i];
            else ++seen[nums[i]];
        }
    }
};
