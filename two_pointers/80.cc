class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = 0, count = 0, total = nums.size();
        for (auto iter = nums.begin(); iter != nums.end();) {
            if (iter == nums.begin()) {
                cur = *iter;
                count = 1;
                ++iter;
            } else {
                if (*iter == cur) {
                    if (count == 2) {
                        nums.erase(iter);
                        --total;
                    } else {
                        ++count;
                        ++iter;
                    }
                } else {
                    cur = *iter;
                    count = 1;
                    ++iter;
                }
            }
        }
        return total;
    }
};
