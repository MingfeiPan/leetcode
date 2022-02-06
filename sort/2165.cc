class Solution {
public:
    long long smallestNumber(long long num) {
        if (num > 0) {
            std::vector<int> nums;
            while (num > 0) {
                nums.emplace_back(num % 10);
                num /= 10;
            }
            // shortest as leading
            int min = 10;
            auto num_iter = nums.begin();
            for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
                if (*iter < min && *iter != 0) {
                    min = *iter;
                    num_iter = iter;
                }
            }
            nums.erase(num_iter);
            std::sort(nums.begin(), nums.end());
            num += min;
            num *= 10;
            for (int i = 0; i < nums.size(); ++i) {
                num += nums[i];
                if (i != (nums.size()-1))
                    num *= 10;
            }
        } else {
            num *= -1;
            std::vector<int> nums;
            while (num > 0) {
                nums.emplace_back(num % 10);
                num /= 10;
            }
            std::sort(nums.begin(), nums.end(), [](int i, int j){
                return i > j;
            });
            for (int i = 0; i < nums.size(); ++i) {
                num += nums[i];
                if (i != (nums.size()-1))
                    num *= 10;
            }
            num *= -1;
        } 
        return num;
    }
};
