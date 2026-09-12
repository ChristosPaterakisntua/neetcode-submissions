class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int range = 0;
        int maxf = 0;
        unordered_map <char, int> seen;
        for (int r = 0; r < s.length(); ++r) {
            ++seen[s[r]];
            maxf = max(maxf, seen[s[r]]);
            while (r-l+1 - maxf > k) {
                --seen[s[l]];
                ++l;
            }
            range = max(range, r-l+1);
        }
        return range;
    }
};
