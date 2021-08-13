class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        std::unordered_map<int, int> m;
        for (const auto& i : arr) {
            ++m[i];
        }
        for (const auto& i : arr) {
            if (m[i] == 0) continue;
            if (i < 0 && i % 2 != 0) return false;
            int j = 0;
            if (i > 0) {
                j = i*2;
            } else {
                j = i / 2;
            }
            if (m[j] == 0) return false;
            --m[i];
            --m[j];
        }
        return true;
    }
};
