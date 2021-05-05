class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int accu = 0, temp = 0;
        for (auto &num : nums) {
            temp = accu;
            accu += num;
            num += temp;
        }
        return nums;
    }
};
