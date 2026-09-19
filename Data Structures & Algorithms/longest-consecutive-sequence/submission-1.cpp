class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int max_len = 0;

        for (int num : nums) {
            // if bottom
            if (!seen.count(num - 1)) {
                // find length
                int cur_len = 1;
                while (seen.count(num + cur_len)) {
                    ++cur_len;
                }
                max_len = max(max_len, cur_len);
            }
        }
        return max_len;
    }
};
