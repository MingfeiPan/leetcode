class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min = INT_MAX, max = INT_MIN;
        for (const auto& num : nums) {
            min = std::min(min, num);
            max = std::max(max, num);
        }
        int gcd = min;
        while (gcd > 0) {
            if (min % gcd == 0 && max % gcd == 0)
                return gcd;
            --gcd;
        }
        return 1;
    }
};
