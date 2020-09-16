class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> ret;
        std::vector<int> cur;
        dfs(target, 0, ret, cur, candidates);
        return ret;
    }
private:
    void dfs(int target, int sum, std::vector<std::vector<int>>& ret, std::vector<int>& cur, std::vector<int>& cands) {
        if (sum > target)
            return;
        if (sum == target) {
            ret.emplace_back(cur);
            return;
        }
        for (auto i : cands) {
            cur.emplace_back(i);
            dfs(target, sum+i, ret, cur, cands);
            cur.pop_back();
        }
        return;
    }
};
