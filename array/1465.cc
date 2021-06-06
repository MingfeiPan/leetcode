class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        std::sort(horizontalCuts.begin(), horizontalCuts.end());
        std::sort(verticalCuts.begin(), verticalCuts.end());
        auto it = horizontalCuts.begin();
        horizontalCuts.insert(it, 0);
        horizontalCuts.emplace_back(h);
        auto itv = verticalCuts.begin();
        verticalCuts.insert(itv, 0);
        verticalCuts.emplace_back(w);
        int hor = 0, ver = 0;
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            hor = std::max(hor, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        for (int i = 1; i < verticalCuts.size(); ++i) {
            ver = std::max(ver, verticalCuts[i] - verticalCuts[i-1]);
        }
        long long ret = (long long)ver * (long long)hor;
        return ret % 1000000007;
    }
};
