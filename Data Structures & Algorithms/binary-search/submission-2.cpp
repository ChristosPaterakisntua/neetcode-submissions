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

    int search(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size()-1, target);
    }
};
