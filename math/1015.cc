class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K <= 0)
            return -1;
        if (K % 2 == 0)
            return -1;
        if (K % 5 == 0)
            return -1;
        int N = 0;
        for (int i = 1; i <= K; ++i) {
            N = (N * 10 + 1) % K;
            if (N == 0)
                return i;
        }
        return -1;
    }
};
