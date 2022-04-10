class KthLargest {
struct cmp
{
  bool operator()(int left, int right) const
  {
    return left > right;
  }
};    
public:
    KthLargest(int k, vector<int>& nums) {
        for (const auto& num : nums) {
            pq.emplace(num);
            if (pq.size() > k) pq.pop();
        }
        k_ = k;
    }
    
    int add(int val) {
        pq.emplace(val);
        if (pq.size() > k_) pq.pop();
        return pq.top();
    }
private:
    std::priority_queue<int, std::vector<int>, cmp> pq;
    int k_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
