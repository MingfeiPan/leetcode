class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> ret;
        std::vector<int> cur;
        std::sort(candidates.begin(), candidates.end());
        dfs(target, 0, ret, cur, candidates, 0);
        return ret;
    }
    
private:
    void dfs(int target, int sum, std::vector<std::vector<int>>& ret, std::vector<int>& cur, std::vector<int>& candis, int start) {
        if (sum > target) {
            return;
        }
        if (target == sum) {
            ret.emplace_back(cur);
            return;
        }
        for (int i = start; i < candis.size(); i++) {
            if (i > start && candis[i] == candis[i-1]) {
                continue;
            }
            cur.emplace_back(candis[i]);
            dfs(target, sum+candis[i], ret, cur, candis, i+1);
            cur.pop_back();
        }
    }
};
