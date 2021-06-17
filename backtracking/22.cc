class Solution {
public:
    vector<string> generateParenthesis(int n) {
        recur("", n , 0);
        return ret;
    }
private:
    void recur(std::string cur, int open, int close) {
        if (open == 0 && close == 0) {
            ret.emplace_back(cur);
            return;
        }
        if (open > 0) {
            recur(cur + "(", open-1, close+1);
        }
        if (close > 0)
            recur(cur + ")", open, close-1);
    }
    std::vector<string> ret;
};
