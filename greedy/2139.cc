class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ret = 0;
        while (target >= 2 && maxDoubles > 0) {
            if (target % 2 == 0) {
                target /= 2;    
                --maxDoubles;
            } else {
                --target;
            }
            ++ret;
        }
        ret += target - 1;
        return ret;
    }
};
