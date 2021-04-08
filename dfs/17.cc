class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::string> ret;
        if (digits.empty())
            return ret;
        std::unordered_map<char, std::string> table = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        std::string temp = "";
        dfs(table, ret, temp, 0, digits);
        return ret;
    }
private:
    void dfs(std::unordered_map<char, std::string> &table, std::vector<std::string> &ret, std::string &temp, int index, std::string digits) {
        if (index == digits.size()) {
            ret.emplace_back(temp);
            return;
        }
        for (const auto& c : table[digits[index]]) {
            temp.push_back(c);
            dfs(table, ret, temp, index+1, digits);
            temp.pop_back();
        }
    }
};
