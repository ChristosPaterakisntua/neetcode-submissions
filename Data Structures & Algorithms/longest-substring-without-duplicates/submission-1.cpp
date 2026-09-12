class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> seen;
        int l = 0;
        int range = 0;
        for (int r = 0; r < s.length(); ++r) {
            while (seen[s[r]]) {
                --seen[s[l]];
                ++l;
            }
            seen[s[r]]++;
            range = max(range, r-l+1);
        }
        return range;
    }
};
