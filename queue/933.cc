class RecentCounter {
public:
    RecentCounter() {
        return;
    }
    
    int ping(int t) {
        q_.push(t);
        while (q_.front() < (t - 3000)) {
            q_.pop();
        }
        return q_.size();
    }
private:
    std::queue<int> q_;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
