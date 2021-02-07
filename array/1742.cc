class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        std::unordered_map<int, int> m;
        int ret = 1;
        for (int i = lowLimit; i <= highLimit; ++i) {
            int count = boxNum(i);
            auto iter = m.find(count);
            if (iter == m.end()) {
                m.emplace(count, 1);
            } else {
                ++iter->second;
                ret = max(ret, iter->second);
            }
        }
        return ret;
    }
private:
    int boxNum(int ballNum) {
        int ret = 0;
        while (ballNum > 0) {
            ret += ballNum % 10;
            ballNum /= 10;
        }
        return ret;
    }
};
