class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int len = (int)position.size();
        
        // cars sorted based on their position
        vector<pair<int, int>> cars; // <pos, speed>
        cars.reserve(len);

        for (int i = 0; i < len; ++i) {
            cars.push_back({position[i], speed[i]});
        }

        sort(
            cars.begin(),
            cars.end(),
            [&](const auto &car1, const auto &car2) {
                return car1.first > car2.first;
            });
        
        int fleets = 0;
        double last_arr_time = -1.0;

        for (const auto & car : cars) {
            // if it arrives later than the last it forms a new fleet
            double time = 1.0 * (target - car.first) / car.second;
            if (time > last_arr_time) {
                ++fleets;
                last_arr_time = time;
            }
        }

        return fleets;
    }
};
