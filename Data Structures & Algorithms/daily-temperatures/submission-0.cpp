class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        for (int i = 0; i < temperatures.size(); ++i) {
            int days = 0;
            for (int j = i+1; j < temperatures.size(); ++j) {
                if (temperatures[j] > temperatures[i]) {
                    days = j - i;
                    break;
                }
            }
            res.push_back(days);
        }
        return res;
    }
};
