class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if (x == 1 && y == 1) {
            if (bound < 2) {
                return {};
            } else {
                return {2};
            }
        }
        int countx = 0, county = 0;
        int cur = 1;
        while (cur <= bound && x != 1) {
            cur *= x;
            ++countx;
        }
        cur = 1;
        while (cur <= bound && y != 1) {
            cur *= y;
            ++county;
        }
        std::unordered_set<int> s;
        for (int i = 0; i <= countx; ++i) {
            for (int j = 0; j <= county; ++j) {
                int total = std::pow(x, i) + std::pow(y, j);
                if (total <= bound) {
                    s.emplace(total);
                }
            }
        }
        std::vector<int> ret(s.begin(), s.end());
        return ret;
    }
};
