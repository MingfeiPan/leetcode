class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        for (int i = 0; i < 1000001; ++i) {
            map_[i] = -1;
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        map_[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return map_[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        map_[key] = -1;
    }
private:
    int map_[1000001];
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
