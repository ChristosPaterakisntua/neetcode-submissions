double eucl_dist(const vector<int> &p) {
    return sqrt(pow(p[0], 2) + pow(p[1], 2));
}


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [&](vector<int> p1, vector<int> p2) {
                return eucl_dist(p1) > eucl_dist(p2);
            };

        priority_queue<
            vector<int>, 
            vector<vector<int>>, 
            decltype(cmp)
        > min_heap(cmp);

        for (const vector<int>& p : points) {
            min_heap.push(p);
        }

        vector<vector<int>> res;
        res.reserve(k);

        while (k--) {
            res.push_back(min_heap.top());
            min_heap.pop();
        }

        return res;
    }
};
