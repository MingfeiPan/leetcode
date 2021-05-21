class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        std::vector<std::string> ret;
        std::string format_pattern = format(pattern);
        for (const auto &word : words) {
            if (format_pattern == format(word)) {
                ret.emplace_back(word);
            }
        }
        return ret;
    }
private:
    std::string format(std::string word) {
        char start = 'a';
        std::string ret = "a";
        int index = 1;
        std::unordered_map<char, char> m;
        m[word[0]] = 'a';
        while (index < word.size()) {
            auto iter = m.find(word[index]);
            if (iter == m.end()) {
                ++start;
                ret += start;
                m[word[index]] = start;
            } else {
                ret += iter->second;
            }
            ++index;
        }
        return ret;
    }
};
