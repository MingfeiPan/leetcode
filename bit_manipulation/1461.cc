class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) {
            return false;
        }
        int need = 1 << k;
        for (int i = 0; i <= (s.size()-k); ++i) {
            std::string cur = s.substr(i, k);
            auto iter = s_.find(cur);
            if (iter == s_.end()) {
                s_.emplace(cur);
                --need;
                if (need == 0)
                    return true;
            }
        }
        return false;
    }
private:
    std::unordered_set<std::string> s_;
};
