class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (const auto& s : words) {
            if (checkPalin(s))
                return s;
        }
        return "";
     }
private:
    bool checkPalin(const std::string& str) {
        for (int i = 0, j = str.size()-1; i < j; ++i, --j) {
            if (str[i] != str[j]) return false;
        }
        return true;
    }
};
