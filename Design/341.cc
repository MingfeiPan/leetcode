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
        for (const auto &i : nestedList) {
            flatten(i);
        }
        iter_ = list_.begin();
    }
    
    int next() {
        int ret = *iter_;
        ++iter_;
        return ret;
    }
    
    bool hasNext() {
        return iter_ != list_.end();
    }
private:
    void flatten(const NestedInteger &nested_integer) {
        if (nested_integer.isInteger()) {
            list_.emplace_back(nested_integer.getInteger());
            return;
        }
        for (const auto &i : nested_integer.getList()) {
            flatten(i);
        }
    }
    std::vector<int> list_;
    std::vector<int>::iterator iter_;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
