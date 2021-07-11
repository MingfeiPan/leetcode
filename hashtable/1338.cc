class Solution {
public:
    int minSetSize(vector<int>& arr) {
        std::unordered_map<int, int> m;
        for (const auto& num : arr) {
            auto iter = m.find(num);
            if (iter == m.end()) {
                m[num] = 1;
            } else {
                ++m[num];
            }
        }
        int half = arr.size() / 2;
        std::vector<std::vector<int>> nums;
        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            std::vector<int> cur(2, 0);
            cur[0] = iter->second;
            cur[1] = iter->first;
            nums.emplace_back(std::move(cur));
        }
        std::sort(nums.begin(), nums.end(), [](std::vector<int>& a, std::vector<int>& b){
            return a[0] > b[0];
        });
        int ret = 0;
        for (const auto& v : nums) {
            if (half <= 0) {
                break;
            } else {
                half -= v[0];
                ++ret;
            }
        }
        return ret;
    }
};
