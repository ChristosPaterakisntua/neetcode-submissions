class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int area = min(heights[i], heights[j]) * (j - i);
                res = max(res, area);
            }
        }
        return res;
    }
};
