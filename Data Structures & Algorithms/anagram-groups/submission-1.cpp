class Solution {
private:
    string hashStr(const string &s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        string hash = "";
        for (int rec : freq) {
            hash += to_string(rec) + ",";
        }
        return hash;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams; // <hash, strings>
        for (const string & s : strs) {
            string hash = hashStr(s);
            anagrams[hash];
            anagrams[hash].push_back(s);
        }
        vector<vector<string>> res;
        res.reserve(anagrams.size());
        for (const auto & item : anagrams) {
            res.push_back(item.second);
        }
        return res;
    }
};
