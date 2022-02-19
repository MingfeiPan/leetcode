class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        std::set<int> s;
        for (const auto& num : nums) {
            if (num % 2 == 0) {
                s.emplace(num);
            } else {
                s.emplace(num*2);
            }
        }
        int ret = *s.rbegin() - *s.begin();
        while (*s.rbegin() % 2 == 0) {
            int cur = *s.rbegin();
            s.erase(cur);
            s.emplace(cur/2);
            ret = std::min(ret, *s.rbegin() - *s.begin());
        }
        return ret;
    }
};
