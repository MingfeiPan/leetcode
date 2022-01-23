class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        std::vector<int> pos, neg, ret;
        for (const auto& i : nums) {
            if (i > 0) {
                pos.emplace_back(std::move(i));
            } else {
                neg.emplace_back(std::move(i));
            }
        }
        for (int i = 0; i < pos.size(); ++i) {
            nums[i*2] = std::move(pos[i]);
            nums[i*2+1] = std::move(neg[i]);
        }
        return nums;
    }
};
