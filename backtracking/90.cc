class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ret;
        std::vector<int> cur;
        recur(ret, 0, nums, cur);
        return ret;
    }
private:
    void recur(std::vector<std::vector<int>>& ret, int index, std::vector<int>& nums, std::vector<int>& cur) {
        ret.emplace_back(cur);
        for (int i = index; i < nums.size(); ++i) {
            if (i != index && nums[i] == nums[i-1])
                continue;
            cur.emplace_back(nums[i]);
            recur(ret, i+1, nums, cur);
            cur.pop_back();
        }
        return;
    }
};
