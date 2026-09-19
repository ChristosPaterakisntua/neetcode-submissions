class Solution {
public:
    int trap(vector<int>& height) {
        const int len = (int)height.size();
        vector<int> prefix_max(len);
        vector<int> suffix_max(len);

        prefix_max[0] = height[0];
        suffix_max[len-1] = height[len-1];

        // fill max arrays
        for (int i = 1; i < len - 1; ++i) {
            prefix_max[i] = max(height[i], prefix_max[i-1]);
            suffix_max[len-1 - i] = max(height[len-1 - i], suffix_max[len - i]);
        }

        int total_water = 0;
        // calc water per square
        for (int i = 1; i < len - 1; ++i) {
            total_water += min(prefix_max[i], suffix_max[i]) - height[i];
        }

        return total_water;
    }
};
