class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        std::unordered_map<int, int> m;
        for (const auto& i : nums) {
            ++m[i];
        }
        std::vector<int> ret;
        for (const auto& i : nums) {
            if (m[i] == 1 && m[i-1] == 0 && m[i+1] == 0)
                ret.emplace_back(i);
        }
        return ret;
    }
};
