struct QTask {
    char id;
    int freq;
    int ready_time;
};


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (const char & task : tasks) {
            freq[task]++;
        }
        
        priority_queue<pair<int, char>> max_heap;
        for (const auto & p : freq) {
            max_heap.push({p.second, p.first});
        }

        queue<QTask> q; // <task, freq, ready_time>

        int time = 0;

        while (!max_heap.empty() || !q.empty()) {
            
            while (!q.empty() && q.front().ready_time <= time) {
                QTask cand = q.front();
                q.pop();
                max_heap.push({cand.freq, cand.id});
            }

            if (!max_heap.empty()) {
                pair<int, char> cur = max_heap.top();
                max_heap.pop();
                
                if (--cur.first) {
                    q.push({cur.second, cur.first, time + n + 1});
                }
                
                ++time;
            }
            else {
                time = q.front().ready_time;
            }
        }

        return time;

    }
};
