class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        if (s.empty())
            return 0;
        std::unordered_map<char, int> map_;
        int ret = 0;
        for (size_t i = 0; i < s.size(); i++) {
            auto iter = map_.find(s[i]);
            if (iter == map_.end()) {
                map_.emplace(s[i], i);
            } else {
                if ((i - iter->second) > ret) {
                    ret = i - iter->second;
                }
            }
        }
        return ret - 1;
    }
};
