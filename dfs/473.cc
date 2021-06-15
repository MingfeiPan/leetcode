class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (const auto &match : matchsticks) {
            sum += match;
        }
        if (sum % 4 != 0)
            return false;
        int target = sum / 4;
        std::vector<int> cur(4, 0);
        std::sort(matchsticks.begin(), matchsticks.end(), [](int a, int b){
            return a > b;
        });
        return dfs(cur, target, 0, matchsticks);
    }
private:
    bool dfs(std::vector<int>& cur, int target, int index, std::vector<int>& nums) {
        if (index == nums.size())
            return cur[0] == target && cur[1] == target && cur[2] == target && cur[3] == target;
        
        for (int i = 0; i < 4; ++i) {
            if ((cur[i] + nums[index]) <= target) {
                cur[i] += nums[index];
                if (dfs(cur, target, index+1, nums))
                    return true;
                cur[i] -= nums[index];
            }
        }
        return false;
    }
};
