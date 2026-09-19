class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // cars sorted based on their position (descending)
        map<int, int, greater<int>> cars; // <pos, speed>
        for (int i = 0; i < (int)position.size(); ++i) {
            cars[position[i]] = speed[i];
        }

        stack<float> arrival_times;

        for (const auto & item : cars) {
            float time = 1.0 * (target - item.first) / item.second;
            // if it arrives later than the last of the front fleet it forms a new fleet
            if (arrival_times.empty() || arrival_times.top() < time) {
                arrival_times.push(time);
            }
        }

        return (int)arrival_times.size();
    }
};
