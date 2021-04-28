class Solution {
public:
    int sumBase(int n, int k) {
        int ret = 0, cur = 0;
        while (n >= k) {
            ret += n % k;
            n = n / k;
        }
        ret += n;
        return ret;
    }
};
