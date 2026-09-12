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
        for (char a = 'a'; a <= 'z'; ++a) {
            if (seen_s[a] != seen_t[a]) return false;
        }
        return true;
    }
};
