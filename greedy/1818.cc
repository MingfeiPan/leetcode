class Solution {
struct Item {
    int diff;
    bool flag;
};
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        std::vector<Item> check(nums1.size());
        int max = 0;
        int index = 0;
        int64_t ret = 0;
        for (size_t i = 0; i < nums1.size(); ++i) {
            int diff;
            if (nums1[i] - nums2[i] >= 0) {
                diff = nums1[i] - nums2[i];
                check[i] = Item{diff, true};
            } else {
                diff = nums2[i] - nums1[i];
                check[i] = Item{diff, false};
            }
            ret += diff;
            if (ret > 1000000007)
                ret -= 1000000007;
            if (diff > max) {
                max = diff;
                index = i;
            }
        }

        int min = check[index].diff;
        for (size_t i = 0; i < nums1.size(); ++i) {
            if (i == index)
                continue;
            int diff = std::abs(nums1[i] - nums2[index]);
            min = std::min(min, diff);
        }
        ret += min - max;
        return ret;
    }
};
