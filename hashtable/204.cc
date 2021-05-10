class Solution {
public:
    int countPrimes(int n) {
        std::vector<int> table(n, 0);
        int ret = 0;
        for (int i = 2; i < n; ++i) {
            if (table[i] == 0) {
                ++ret;
                for (int j = 2; i*j < n; ++j) {
                    table[i*j] = 1;
                }                
            }
        }
        return ret;
    }
};
