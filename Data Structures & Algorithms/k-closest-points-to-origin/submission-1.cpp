int sqr_dist(const vector<int> &p) {
    return p[0] * p[0] + p[1] * p[1];
}


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [&](vector<int> e1, vector<int> e2) {
                return e1[0] > e2[0];
            };

        priority_queue<
            vector<int>, 
            vector<vector<int>>, 
            decltype(cmp)
        > min_heap(cmp);

        for (const vector<int>& p : points) {
            vector<int> entry = {sqr_dist(p), p[0], p[1]};
            min_heap.push(entry);
        }

        vector<vector<int>> res;
        res.reserve(k);

        while (k--) {
            const vector<int> & top = min_heap.top();
            res.push_back({top[1], top[2]});
            min_heap.pop();
        }

        return res;
    }
};
