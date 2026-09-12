class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        sort(nums.begin(), nums.end(), greater<int>());
        for (int num : nums) {
            if ((int)min_heap.size() < k || num > min_heap.top()) {
                min_heap.push(num);
            }
        }
    }
    
    int add(int val) {
        int cur_elements = (int)min_heap.size();
        if (cur_elements < k) {
            min_heap.push(val);
        }
        else if (val > min_heap.top()) {
            min_heap.pop();
            min_heap.push(val);
        }

        return min_heap.top();
    }
};
