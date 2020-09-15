class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> ret;
        std::vector<int> cur;
        dfs(n, 0, k, 0, ret, cur, 0);
        return ret;
    }
private:
    void dfs(int sum, int cur_sum, int num, int cur_num, std::vector<std::vector<int>>& ret, std::vector<int>& cur, int index) {
        if (cur_sum > sum || cur_num > num) {
            return;
        }
        if (cur_sum == sum && cur_num == num) {
            ret.emplace_back(cur);
            return;
        }
        for (int i = index + 1; i <= 9; i++) {
            cur.emplace_back(i);
            dfs(sum, cur_sum+i, num, cur_num+1, ret, cur, i);
            cur.pop_back();
        }
        return;
    }
};
