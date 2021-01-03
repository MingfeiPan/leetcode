class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        std::sort(boxTypes.begin(), boxTypes.end(), [](std::vector<int> a, std::vector<int> b){
            return a[1] > b[1]; 
        });
        int ret = 0;
        for (auto& box : boxTypes) {
            if (truckSize <= 0)
                break;
            if (truckSize < box[0]) {
                ret += truckSize * box[1];
                break;
            } else {
                ret += box[0] * box[1];
                truckSize -= box[0];
            }
        }
        return ret;
    }
};
