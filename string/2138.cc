class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        std::vector<std::string> ret;
        std::string cur;
        for (int i = 0; i < s.size(); i += k) {
            ret.emplace_back(s.substr(i, k));
        }
        while (ret[ret.size()-1].size() < k) {
            ret[ret.size()-1] += fill;
        }
        return ret;
    }
};
