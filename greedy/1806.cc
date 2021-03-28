class Solution {
public:
    int reinitializePermutation(int n) {
        std::vector<int> init(n);
        std::iota(init.begin(), init.end(), 0);
        std::vector<int> pre = init, cur = init;

        int round = 0;
        while (true) {
            ++round;
            for (size_t i = 0; i < cur.size(); ++i) {
                if (i % 2 == 0) {
                    cur[i] = pre[i/2];
                } else {
                    cur[i] = pre[n / 2 + (i - 1) / 2];
                }
            }
            if (check(init, cur)) {
                return round;
            } 
            pre.swap(cur);
        }
        return -1;
    }
private:
    bool check(std::vector<int>& v1, std::vector<int>& v2) {
        for (size_t i = 0; i < v1.size(); ++i) {
            if (v1[i] != v2[i])
                return false;
        }
        return true;
    }
};
