class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num);
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
