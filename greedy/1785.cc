class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int64_t target = 0;
        for (const auto &num : nums) {
            target += num;
        }
        target = goal - target;
        if (target < 0)
            target *= -1;
        int left = target % limit;
        if (left != 0) {
            return (target - left) / limit + 1;    
        } else {
            return target / limit;
        }
    }
};
