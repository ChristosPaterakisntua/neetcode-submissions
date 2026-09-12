class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};