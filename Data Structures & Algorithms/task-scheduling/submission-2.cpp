struct QTask {
    int freq;
    int ready_time;
};


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {};
        for (const char & task : tasks) {
            freq[task - 'A']++;
        }
        
        priority_queue<int> max_heap;
        for (const int & f : freq) {
            if (f) max_heap.push(f);
        }

        queue<QTask> q; // <freq, ready_time>

        int time = 0;

        while (!max_heap.empty() || !q.empty()) {
            
            while (!q.empty() && q.front().ready_time <= time) {
                QTask cur = q.front();
                q.pop();
                max_heap.push(cur.freq);
            }

            if (!max_heap.empty()) {
                int cur = max_heap.top();
                max_heap.pop();
                
                if (--cur) {
                    q.push({cur, time + n + 1});
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
