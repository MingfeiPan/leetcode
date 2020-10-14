class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size())
            return false;
        if (A == B) {
            std::unordered_set<char> set_;
            for (auto&& c : A) {
                auto iter = set_.find(c);
                if (iter != set_.end()) {
                    return true;
                } else {
                    set_.emplace(c);
                }
            }
            return false;
        } else {    
            std::vector<size_t> list_;
            int diff = 0;
            char pre;
            for(size_t i = 0; i < A.size(); i++) {
                if (i == 0) {
                    pre = A[i];
                } else {
                    if (pre != A[i]) {
                        diff++;
                        pre = A[i];
                    }
                }
                if (A[i] != B[i]) {
                    list_.emplace_back(i);
                }
            }
            if (A == B && diff == 0)
                return true;
            if (list_.size() != 2)
                return false;
            if (A[list_[0]] == B[list_[1]] && A[list_[1]] == B[list_[0]])
                return true;
            return false;
        }
    }
};
