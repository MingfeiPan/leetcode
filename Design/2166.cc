class Bitset {
public:
    Bitset(int size) {
        for (int i = 0; i < size; ++i) {
            zeros_.emplace(i);
        }
        one_count_ = 0;
        total_ = size;
    }
    
    void fix(int idx) {
        auto iter_ones = ones_.find(idx);
        if (iter_ones == ones_.end()) {
            zeros_.erase(idx);
            ones_.emplace(idx); 
            ++one_count_;
        }
    }
    
    void unfix(int idx) {
        auto iter_zeros = zeros_.find(idx);
        if (iter_zeros == zeros_.end()) {
            ones_.erase(idx);
            zeros_.emplace(idx); 
            --one_count_;
        }
    }
    
    void flip() {
        std::swap(ones_, zeros_);
        one_count_ = total_ - one_count_;
    }
    
    bool all() {
        return one_count_ == total_;
    }
    
    bool one() {
        return one_count_ > 0;
    }
    
    int count() {
        return one_count_;
    }
    
    string toString() {
        std::ostringstream s;
        for (int i = 0; i < total_; ++i) {
            auto iter = ones_.find(i);
            if (iter == ones_.end()) {
                s << 0;
            } else {
                s << 1;
            }
        }
        return s.str();
    }
private:
    // std::vector<int> sets_;
    std::unordered_set<int> ones_;
    std::unordered_set<int> zeros_;
    int one_count_;
    int total_;
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
