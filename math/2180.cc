class Solution {
public:
    int countEven(int num) {
        int cur = 0, sum = 0, ret = 0;
        while (num > 0) {
            cur = num;
            sum = 0;
            while (cur > 0) {
                sum += cur % 10;
                cur /= 10;
            }
            if (sum % 2 == 0) ++ret;
            --num;
        }
        
        return ret;
    }
};
