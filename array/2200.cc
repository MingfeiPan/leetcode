class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        std::vector<int> check;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == key) check.emplace_back(i);
        }
        std::vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            for (const auto& c : check) {
                if (std::abs(c-i) <= k) {
                    ret.emplace_back(i);
                    break;
                }
            }
        }
        return ret;
    }
};
