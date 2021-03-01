class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        std::unordered_set<int> types(candyType.begin(), candyType.end());
        int limit = candyType.size() / 2;
        if (types.size() < limit) {
            return types.size();
        } else {
            return limit;
        }
    }
};
