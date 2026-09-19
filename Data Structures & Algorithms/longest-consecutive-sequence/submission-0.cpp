class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) seen.insert(num);

        unordered_map<int, int> lengths; // <bottom, length>

        // find all bottoms
        for (int num : nums) {
            if (!seen.count(num - 1)) {
                lengths[num] =  1;
            }
        }

        // find max length
        int max_len = 0;

        for (auto & item : lengths) {
            int bottom = item.first;
            while (seen.count(bottom + item.second)) {
                item.second++;
            }
            max_len = max(max_len, item.second);
        }

        return max_len;
    }
};
