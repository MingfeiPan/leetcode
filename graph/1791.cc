class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        for (const auto &i : edges[0]) {
            for (const auto &ii: edges[1]) {
                if (i == ii)
                    return i;
            }
        }
        return 0;
    }
};
