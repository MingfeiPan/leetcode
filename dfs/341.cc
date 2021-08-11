/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        recur(nestedList);
        index_ = 0;
    }
    
    int next() {
        return list_[index_++];    
    }
    
    bool hasNext() {
        return list_.size() > index_;
    }
private:
    void recur(vector<NestedInteger> &nestedList) {
        for (const auto ni : nestedList) {
            if (ni.isInteger()) {
                list_.emplace_back(ni.getInteger());
            } else {
                auto ret = ni.getList();
                recur(ret);
            }
        }
        return;
    }
    std::vector<int> list_;
    int index_;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
