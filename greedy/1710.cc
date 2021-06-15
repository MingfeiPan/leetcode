class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        std::sort(boxTypes.begin(), boxTypes.end(), [](std::vector<int>& v1, std::vector<int>& v2){
            return v1[1] > v2[1];
        });
        int ret = 0;
        for (const auto &box : boxTypes) {
            if (truckSize >= box[0]) {
                ret += box[0] * box[1];
                truckSize -= box[0];
            } else {
                ret += truckSize * box[1];
                break;
            }
        }
        return ret;
    }
};
