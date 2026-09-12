class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> freq(2002, 0);
        for (int i = 0; i < nums.size(); ++i) {
            ++freq[nums[i] + 1000];
        }
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            auto iter_max = max_element(begin(freq), end(freq));
            int idx_max = distance(begin(freq), iter_max);
            res.push_back(idx_max-1000);
            freq[idx_max] = 0;
        }
        return res;
    }
};
