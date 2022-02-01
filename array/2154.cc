class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool found = false;
        while (true) {
            found = false;
            for (const auto& num : nums) {
                if (num == original) {
                    original += original;
                    found = true;
                    break;
                }
            }
            if (!found) break;
        }
        return original;
    }
};
