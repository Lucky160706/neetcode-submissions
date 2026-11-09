class MyHashSet {
public:
    MyHashSet() {
    }
    
    void add(int key) {
        se.insert(key);
    }
    
    void remove(int key) {
        if (se.find(key) != se.end()) se.erase(key);
    }
    
    bool contains(int key) {
        return se.find(key) != se.end();
    }
private:
    unordered_set<int> se;

};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */