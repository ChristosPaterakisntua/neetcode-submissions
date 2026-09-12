class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> seen;
        for (int i = 0; i < size; ++i) {
            if (!seen[nums[i]]) ++seen[nums[i]];
            else return true;
        }
        return false;
    }
};