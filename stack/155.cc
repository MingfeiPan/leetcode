class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        main_.emplace_back(val);
        if (min_.empty() || val <= min_[min_.size()-1]) {
            min_.emplace_back(val);
        }
    }
    
    void pop() {
        if (!min_.empty() && main_[main_.size()-1] == min_[min_.size()-1])
            min_.pop_back();
        main_.pop_back();
    }
    
    int top() {
        if (main_.empty())
            return 0;
        return main_[main_.size()-1];
    }
    
    int getMin() {
        if (min_.empty())
            return 0;
        return min_[min_.size()-1];
    }
private:
    std::vector<int> main_;
    std::vector<int> min_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
