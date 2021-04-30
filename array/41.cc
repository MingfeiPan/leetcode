class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        std::unordered_set<int> s(nums.begin(), nums.end());
        int index = 1;
        while (index <= INT_MAX) {
            auto iter = s.find(index);
            if (iter == s.end()) {
                return index;
            } else {
                ++index;
            }
        }
        return -1;
    }
};
