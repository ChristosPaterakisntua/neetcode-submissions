class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> seen(n, 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (seen[nums[i]]) return nums[i];
            else ++seen[nums[i]];
        }
    }
};
