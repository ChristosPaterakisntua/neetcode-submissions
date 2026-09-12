class Solution {
public:
    bool isAnagram(string s, string t) {
        int len = s.length();
        if (len != t.length()) return false;
        unordered_map <char, int> seen_s;
        unordered_map <char, int> seen_t;
        for (int i = 0; i < len; ++i) {
            ++seen_s[s[i]];
            ++seen_t[t[i]];
        }
        return seen_s == seen_t;
    }
};
