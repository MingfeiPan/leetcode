class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        if (patterns.empty() || word.empty())
            return 0;
        int ret = 0;
        for (const auto &pattern : patterns) {
            if (check(word, pattern))
                ++ret;
        }
        return ret;
    }
private:
    bool check(std::string target, std::string pattern) {
        int sizet = target.size();
        int sizep = pattern.size();
        if (sizet < sizep)
            return false;
        for (int i = 0; i <= (sizet - sizep); ++i) {
            if (pattern == target.substr(i, sizep)) {
                return true;
            }
        }
        return false;
    }
};
