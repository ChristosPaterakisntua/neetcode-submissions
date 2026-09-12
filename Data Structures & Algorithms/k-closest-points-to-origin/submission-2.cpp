int sq_dist(const vector<int> & p) {
    return p[0] * p[0] + p[1] * p[1];
}


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto cmp = [&](const vector<int> & e1, const vector<int> & e2) {
            return e1[0] < e2[0];
        };

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            decltype(cmp)
        > max_heap(cmp);

        for (const vector<int> & p : points) {
            max_heap.push({sq_dist(p), p[0], p[1]});
        
            if ((int)max_heap.size() > k) {
                max_heap.pop();
            }
        }

        vector<vector<int>> res;
        res.reserve(k);

        while (k--) {
            const vector<int> & top = max_heap.top();
            res.push_back({top[1], top[2]});
            max_heap.pop();
        }

        return res;
    }
};
