class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int l = 0, r = matrix.size() * m - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int mid_num = matrix[mid / m][mid % m];
            if (mid_num == target) return true;
            else if (mid_num < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};
