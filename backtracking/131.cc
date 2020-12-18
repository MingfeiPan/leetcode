class Solution {
public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string>> ret;
        std::vector<std::string> cur;
        recur(ret, s, 0, cur);
        return ret;
    }
private:
    void recur(std::vector<std::vector<std::string>>& ret, string s, int index, std::vector<std::string>& cur) {
        if (index == s.size()) {
            // ret.emplace_back(std::move(cur));
            ret.emplace_back(cur);
            return;
        }
        for (int i = index+1; i <= s.size(); ++i) {
            std::string temp = s.substr(index, i-index);
            if (isPalin(temp)) {
                cur.emplace_back(std::move(temp));
                recur(ret, s, i, cur);
                cur.pop_back();
            }
        }
    }
    bool isPalin(std::string& s) {
        for (int i = 0, j = s.size()-1; i < j; ++i, --j) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};
