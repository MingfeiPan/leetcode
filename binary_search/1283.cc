class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = 1000000, mid = (low + high) / 2;
        while (low < high) {
            if (runOnce(nums, mid) > threshold) {
                low = mid+1;
            } else {
                high = mid;
            }
            mid = (low+high) / 2;
        }
        return high;
    }
private:
    int div(int& a, int&b) {
        if (a < b) return 1;
        if (a % b == 0) {
            return a / b;
        } else {
            return a / b + 1;
        }
    }
    int sum(std::vector<int>& nums) {
        int ret = 0;
        for (auto&& num : nums)
            ret += num;
        return ret;
    }
    int runOnce(std::vector<int>& nums, int& divisor) {
        int ret = 0;
        for (auto&& num : nums) {
            ret += div(num, divisor);
        }
        return ret;
    }
};
