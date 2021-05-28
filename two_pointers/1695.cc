class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0, right = 0, ret = 0, cur = 0;
        std::unordered_map<int, int> m;
        while (right < nums.size()) {
            while (right < nums.size() && !check(m)) {
                auto iter = m.find(nums[right]);
                if (iter == m.end()) {
                    m.emplace(nums[right], 1);
                } else {
                    ++iter->second;
                }
                cur += nums[right];
                ++right;
            }
            ret = max(ret, cur-nums[right-1]);
            while (left < right && check(m)) {
                auto iter = m.find(nums[left]);
                --iter->second;
                cur -= nums[left];
                ++left;
            }
            ret = max(ret, cur);
        }
        return ret;
    }
private:
    bool check(std::unordered_map<int, int>& m) {
        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            if (iter->second > 1) {
                return true;
            }            
        }
        return false;
    }
};
