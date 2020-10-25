class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        std::vector<bool> ret;
        for (int i = 0; i < l.size(); i++) {
            std::vector<int> temp;
            bool flag = false;
            for (int k = l[i]; k <= r[i]; k++) {
                temp.emplace_back(nums[k]);
            }
            std::sort(temp.begin(), temp.end());
            for (int j = 1; j < temp.size()-1; j++) {
                if ((temp[j] - temp[j-1]) != (temp[j+1] - temp[j])) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                ret.emplace_back(false);    
            } else {
                ret.emplace_back(true);    
            }
        }
        return ret;
    }
};
