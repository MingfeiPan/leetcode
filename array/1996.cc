class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        std::sort(properties.begin(), properties.end(), [](std::vector<int>& v1, std::vector<int>& v2){
            if (v1[0] == v2[0])
                return v1[1] > v2[1];
            return v1[0] < v2[0];
        });
        int ret = 0, max_def = 0;
        for (int i = properties.size() - 1; i >= 0; --i) {
            if (properties[i][1] < max_def) {
                ++ret;
            }
            max_def = std::max(properties[i][1], max_def);
        }
        return ret;
    }
};
