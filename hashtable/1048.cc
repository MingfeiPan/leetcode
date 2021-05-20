class Solution {
public:
    int longestStrChain(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](std::string &s1, std::string &s2){
            return s1.size() < s2.size();
        });
        std::unordered_map<std::string, int> m;
        int ret = 0;
        for (const auto &word : words) {
            std::string temp = "";
            int cur = 0;
            for (int i = 0; i < word.size(); ++i) {
                temp = word.substr(0, i) + word.substr(i+1);
                auto iter = m.find(temp);
                if (iter != m.end()) {
                    cur = std::max(cur, iter->second + 1);
                } else {
                    cur = std::max(cur, 1);
                }
            }
            m[word] = cur;
            ret = std::max(ret, cur);
        }
        return ret;
    }
};
