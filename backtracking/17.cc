class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::string> ret;
        if (digits.empty()) {
            return ret;
        }
        std::unordered_map<char, std::string> m_ = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        dfs(ret, m_, 0, "", digits);
        return ret;
    }
private:
    void dfs(std::vector<std::string>& ret, std::unordered_map<char, std::string>& source, int index, std::string cur, std::string digits) {
        if (index == digits.size()) {
            ret.emplace_back(cur);
            return;
        }
        for (auto c : source[digits[index]]) {
            cur.push_back(c);
            dfs(ret, source, index+1, cur, digits);
            cur.pop_back();
        }
    }
};
