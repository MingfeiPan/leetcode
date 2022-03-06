class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int>& b){
            return a[0] < b[0];
        });
        int ret = 0, left = -1, right = -1;
        for (auto& val : intervals) {
            if (val[0] > left && val[1] > right) {
                ret++;
                left = val[0];
            }
            right = max(val[1], right);
        }
        return ret;
    }
};


class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int>& b){
            return a[0] < b[0];
        });
        int ret = 0, left = -1, right = -1;
        for (auto& val : intervals) {
            if (val[0] > left && val[1] > right) ++ret;
            if (val[1] > right) {
                left = val[0];
                right = val[1];
            }
        }
        return ret;
    }
};
