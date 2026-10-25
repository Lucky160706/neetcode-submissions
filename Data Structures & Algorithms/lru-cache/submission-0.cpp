class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        auto it = mp[key];
        cache.splice(cache.end(), cache, it);
        return it->second;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];
            it->second = value;
            cache.splice(cache.end(), cache, it);
            return;
        }

        if (cache.size() == capacity) {
            int lruKey = cache.front().first;
            mp.erase(lruKey);
            cache.pop_front();
        }

        cache.push_back({key, value});
        mp[key] = prev(cache.end());
    }

private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
};
