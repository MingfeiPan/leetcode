class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        if (nums.empty()) return nums;
        std::vector<int> odd, even;
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                even.emplace_back(nums[i]);    
            } else {
                odd.emplace_back(nums[i]);    
            }
        }
        std::sort(even.begin(), even.end());
        std::sort(odd.begin(), odd.end(), [](int i, int j){
            return i > j;
        });
        for (int i = 0; i < even.size(); ++i) {
            nums[i*2] = even[i];
            if ((i*2+1) < nums.size())
                nums[i*2+1] = odd[i];
        }
        return nums;
    }
};
