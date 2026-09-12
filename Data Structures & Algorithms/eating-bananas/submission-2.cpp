class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int highest_pile = 0;
        for (int p : piles) {
            highest_pile = max(highest_pile, p);
        }
        int l = 1, r = highest_pile;
        int res = r;
        while (l <= r) {
            int mid = (l + r) / 2;
            int total_hours = 0;
            for (int p : piles) total_hours += (p + mid - 1) / mid;
            if (total_hours <= h) {
                res = min(res, mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return res;

    }
};
