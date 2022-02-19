class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int64_t ret = INT64_MAX, sum = 0, temp = 0;
        std::sort(beans.begin(), beans.end());
        for (const auto& i : beans) {
            sum += i;
        }
        for (int i = 0; i < beans.size(); ++i) {
            temp = sum - (beans.size() - i) * beans[i];
            ret = std::min(ret, temp);
        }
        return ret;
    }
};
