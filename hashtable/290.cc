class Solution {
public:
    bool wordPattern(string pattern, string str) {
        std::vector<std::string> words;
        std::string cur = "";
        for (const auto& c : str) {
            if (c == ' ') {
                std::string temp = "";
                temp.swap(cur);
                words.emplace_back(std::move(temp));
            } else {
                cur += c;
            }
        }
        words.emplace_back(std::move(cur));
        if (words.size() != pattern.size()) return false;
        std::unordered_map<std::string, int> m;
        for (int i = 0; i < pattern.size(); ++i) {
            auto s1 = "pattern" + std::to_string(pattern[i]);
            auto s2 = "word" + words[i];
            auto pattern_iter = m.find(s1);
            if (pattern_iter == m.end()) {
                m[s1] = i;
            }
            auto word_iter = m.find(s2);
            if (word_iter == m.end()) {
                m[s2] = i;
            }            
            if (m[s1] != m[s2]) return false;
        }
        return true;
    }
};
