class MyHashSet {
public:
        set<int> se;

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
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */