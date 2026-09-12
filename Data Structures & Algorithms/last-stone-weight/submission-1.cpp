class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap;
        for (int stone : stones) {
            max_heap.push(stone);
        }
        while ((int)max_heap.size() > 1) {
            int s1 = max_heap.top();
            max_heap.pop();
            int s2 = max_heap.top();
            max_heap.pop();
            if (s1 -  s2) {
                max_heap.push(abs(s1 - s2));
            }
        }
        return max_heap.size() ? max_heap.top() : 0;
    }
};
