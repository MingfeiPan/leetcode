class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ret = 0, cur = 0;
        dfs(nums, cur, ret, 0);
        return ret;
    }
private:
    void dfs(std::vector<int>& nums, int cur, int& ret, int index) {
        ret += cur;
        for (int i = index; i < nums.size(); ++i) {
            dfs(nums, cur ^ nums[i], ret, i+1);
        }
        return;
    }
};
