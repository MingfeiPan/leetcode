class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        // find both way
        int length = nums.size();
        std::vector<int> ups(length, 1);
        for (int i = 1; i < length; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    ups[i] = std::max(ups[i], ups[j]+1);
                }
            }
        }
        
        std::vector<int> downs(length, 1);
        for (int i = length-2; i > 0; --i) {
            for (int j = length-1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    downs[i] = std::max(downs[i], downs[j]+1);
                }
            }
        }
        
        int ret = 0;
       
        for (int i = 1; i < (length-1); ++i) {
            // a valid peek
            if (ups[i] > 1 && downs[i] > 1)
                ret = std::max(ret, ups[i]+downs[i]-1);
        }
        return length - ret;
    }
};
