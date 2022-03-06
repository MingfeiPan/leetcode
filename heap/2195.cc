class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        auto cmp = [](int left, int right){
            return left > right;
        };
        std::priority_queue<int, std::vector<int>, decltype(cmp)> q(cmp);
        for (const auto& num : nums) {
            q.emplace(std::move(num));
        }
        // while (!q.empty()) {
        //     std::cout << q.top() << std::endl;
        //     q.pop();
        // }
        int64_t ret = 0;
        int start = 0;
        while (!q.empty()) {
            int cur = q.top();
            q.pop();
            if (cur == start) continue;
            int count = cur - start - 1;
            if (count == 0) {
                start = cur;
                continue;
            }
            if (count >= k) {
                ret += int64_t((start + 1 + start + k)) * int64_t(k) / 2;
                return ret;
            } else {
                ret += int64_t((start + cur)) * int64_t(count) / 2;
                k -= count;
                start = cur;
            }
        }
        if (k > 0) {
            ret += int64_t((start + 1 + start + k)) * int64_t(k) / 2;
        }
        return ret;
    }
};
