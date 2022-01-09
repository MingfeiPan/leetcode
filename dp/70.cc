class Solution {
public:
    int climbStairs(int n) {
       int a = 1, b = 1;
        while (n > 1) {
            int temp = a+b;
            a = b;
            b = temp;
            --n;
        }
        return b;
    }
};
