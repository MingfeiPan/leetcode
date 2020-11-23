class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<int> cur;
        std::vector<std::vector<int>> ret;
        recur(nums, ret, cur, 0);
        return ret;
    }
private:
    void recur(std::vector<int>& nums, std::vector<std::vector<int>>& ret, std::vector<int>& cur, int index) {
        ret.emplace_back(cur);
        for (int i = index; i < nums.size(); ++i) {
            cur.emplace_back(nums[i]);
            recur(nums, ret, cur, i+1);
            cur.pop_back();
        }
    }
};
