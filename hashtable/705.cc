class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        myset[key] = 1;
    }
    
    void remove(int key) {
        myset[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if (myset[key] == 1) {
            return true;
        }
        return false;
    }
private:
    int myset[1000000];
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
