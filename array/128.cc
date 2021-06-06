class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> s;
        for (const auto &num : nums) {
            s.emplace(num);
        }
        int ret = 0;
        for (const auto &num : nums) {
            // 检查这个num 是否已经在一个答案序列里, 如果不在 以这个为起点检查答案序列
            auto iter = s.find(num-1);
            if (iter == s.end()) {
                int cur = num;
                int count = 1;
                while (true) {
                    ++cur;
                    auto iter_cur = s.find(cur);
                    if (iter_cur != s.end()) {
                        ++count;
                    } else {
                        break;
                    }
                }
                ret = std::max(count, ret);
            }
        }     
        return ret;
    }
};
