class Solution {
public:
    int specialArray(vector<int>& nums) {
        int total = nums.size();
        while (total > 0) {
            int cur = 0;
            for (auto& num : nums) {
                if (num >= total)
                    cur++;
            }
            if (total == cur)
                return total;
            total--;
        }
        return -1;
    }
};
