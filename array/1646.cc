class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        std::vector<int> nums;
        int cur = 0, ret = 1, index = 2;
        nums.emplace_back(0);
        nums.emplace_back(1);
        while (index <= n) {
            if ((index % 2) == 0) {
                cur = nums[index / 2];
            } else {
                cur = nums[(index-1)/2] + nums[(index-1)/2+1];
            }
            if (cur > ret) {
                ret = cur;
            }
            nums.emplace_back(cur);
            index++;
        }
        return ret;
    }
};

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        std::vector<int> nums;
        int cur = 0, ret = 1, index = 2;
        nums.emplace_back(0);
        nums.emplace_back(1);
        while (index <= n) {
            if ((index % 2) == 0) {
                cur = nums[index / 2];
            } else {
                cur = nums[(index-1)/2] + nums[(index-1)/2+1];
            }
            if (cur > ret) {
                ret = cur;
            }
            nums.emplace_back(cur);
            index++;
        }
        return ret;
    }
};
