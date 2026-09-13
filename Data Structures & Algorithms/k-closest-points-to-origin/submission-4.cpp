int sq_dist(const vector<int> & p) {
    return p[0] * p[0] + p[1] * p[1];
}


struct Point {
    int sq_dist;
    int x;
    int y;
};


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto cmp = [&](const Point &p1, const Point &p2) {
            return p1.sq_dist < p2.sq_dist;
        };

        priority_queue<
            Point,
            vector<Point>,
            decltype(cmp)
        > max_heap(cmp);

        for (const vector<int> & p : points) {
            Point cur = {sq_dist(p), p[0], p[1]};
            if ((int)max_heap.size() < k) {
                max_heap.push(cur);
            }
            else if (cur.sq_dist < max_heap.top().sq_dist) {
                max_heap.pop();
                max_heap.push(cur);
            }
        }

        vector<vector<int>> res;
        res.reserve(k);

        while (k--) {
            const Point & top = max_heap.top();
            res.push_back({top.x, top.y});
            max_heap.pop();
        }

        return res;
    }
};
