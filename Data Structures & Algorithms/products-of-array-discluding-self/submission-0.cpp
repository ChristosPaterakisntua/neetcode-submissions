class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> forward_prods, backward_prods;

        int len = (int)nums.size();
        int left_product = 1;
        int right_product = 1;

        for (int i = 0; i < len; ++i) {
            forward_prods.push_back(left_product);
            backward_prods.push_back(right_product);
            left_product *= nums[i];
            right_product *= nums[len - 1 - i];
        } 

        vector<int> res;
        for (int i = 0; i < len; ++i) {
            res.push_back(forward_prods[i] * backward_prods[len - 1 - i]);
        }

        return res;
    }
};
