class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        std::unordered_set<char> bls;
        for (const auto& c : brokenLetters) {
            bls.emplace(c);
        }
        int ret = 0;
        bool flag = true;
        for (const auto& c : text) {
            if (c == ' ') {
                if (flag) {
                    ++ret;
                } else {
                    flag = true;
                }
            } else {
                if (flag) {
                    auto iter = bls.find(c);
                    if (iter != bls.end())
                        flag = false;
                }
            }
        }
        if (text.size() > 0 && flag)
            ++ret;
        return ret;
    }
};
