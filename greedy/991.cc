class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ret = 0;
        while (target > startValue) {
            ++ret;
            if (target % 2 == 1)
                ++target;
            else 
                target /= 2;
        }
        return ret + startValue - target;
    }
};
