class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (const string& str : strs) {
            res += to_string((int)str.length()) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while (i < (int)s.size()) {
            // get len
            int j = i;
            while (s[j] != '#') {
                ++j;
            }
            int len = stoi(s.substr(i, j - i));
            // skip '#'
            ++j;
            // get word
            res.push_back(s.substr(j, len));
            // move forward
            i = j + len;
        }

        return res;
    }
};
