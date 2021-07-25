class Solution {
public:
    int getLucky(string s, int k) {
        std::string nums;
        for (const auto& c : s) {
            nums += std::to_string(c - 'a' + 1);
        }
        int sum = 0;
        for (const auto& c : nums) {
            sum += c - '0';
        }
        int left = 0, cur = 0;
        while (k > 1) {
            cur = 0;
            while (sum > 0) {
                left = sum % 10;
                sum /= 10;
                cur += left;                
            }
            sum = cur;
            --k;
        }
        return sum;
    }
};
