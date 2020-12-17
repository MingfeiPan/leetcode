class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        std::vector<int> ret;
        int init_index = nums.size()-1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                if (i > 0 && std::abs(nums[i-1]) < nums[i]) {
                    init_index = i - 1;
                } else {
                    init_index = i;
                }
                break;
            }
        }
        ret.emplace_back(nums[init_index]*nums[init_index]);
        int left = init_index-1;
        int right = init_index+1;
        while (left >= 0 && right < nums.size()) {
            if (std::abs(nums[left]) < std::abs(nums[right])) {
                ret.emplace_back(nums[left]*nums[left]);
                --left;
            } else {
                ret.emplace_back(nums[right]*nums[right]);
                ++right;
            }
        }
        while (left >= 0) {
            ret.emplace_back(nums[left]*nums[left]);
            --left;
        }
        while (right < nums.size()) {
            ret.emplace_back(nums[right]*nums[right]);
            ++right;
        }
        return ret;
    }
};
