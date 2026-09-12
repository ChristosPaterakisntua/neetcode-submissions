class Solution {
public:
    int binary_search(vector<int>& nums, int l, int r, int target) {
        int mid = (r+l) / 2;
        if (l > r) return -1;
        if (nums[mid] == target) return mid;
        return ((nums[mid] < target) ?
                binary_search(nums, mid+1, r, target) :
                binary_search(nums, l, mid-1, target));
        
    }

    int findEdge(vector<int> &nums) {
        int l = 0, r = nums.size()-1;
        int edge = 0;
        while (l <= r) {
            if (nums[l] < nums[r]) {
                edge = (nums[edge] < nums[l]) ? edge : l;
                break;
            }
            int m = (l + r) / 2;
            edge = (nums[edge] < nums[m]) ? edge : m;
            if (nums[l] <= nums[m]) l = m + 1;
            else r = m - 1;
        }
        return edge;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int edge = findEdge(nums);
        int cand1 = binary_search(nums, 0, edge-1, target);
        int cand2 = binary_search(nums, edge, n-1, target);
        if (cand1 == cand2 && cand1 == -1) return -1;
        else if (cand1 != -1) return cand1;
        else return cand2;
    }
};
