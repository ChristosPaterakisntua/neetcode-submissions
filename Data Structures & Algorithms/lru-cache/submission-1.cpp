class LRUCache {
public:
    LRUCache(int capacity) :
    myCapacity(capacity) {}
    
    int get(int key) {
        for (int i = 0; i < keys.size(); ++i) {
            if (keys[i].first == key) {
                int tmp = keys[i].second;
                keys.erase(keys.begin() + i);
                keys.push_back(make_pair(key, tmp));
                return tmp; 
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for (int i = 0; i < keys.size(); ++i) {
            if (keys[i].first == key) {
                keys.erase(keys.begin()+i);
                keys.push_back(make_pair(key, value));
                return;
            }
        }
        if (keys.size() == myCapacity) keys.erase(keys.begin());
        keys.push_back(make_pair(key, value));
    }
private:
    vector<pair<int, int>> keys;
    int myCapacity;
};
