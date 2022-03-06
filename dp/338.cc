class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> ret(n+1, 0);
        for (int i = 0; i <= n; ++i) {
            ret[i] = ret[i/2] + i%2;
        }
        return ret;
    }
};
