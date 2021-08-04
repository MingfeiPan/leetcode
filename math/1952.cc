class Solution {
public:
    bool isThree(int n) {
        int div = 1, count = 0;
        while (div <= n) {
            if (n % div == 0)
                ++count;
            if (count > 3)
                return false;
            ++div;
        }
        
        if (count != 3)
            return false;
        return true;
    }
};
