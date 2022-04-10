class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        auto cmp = [](int left, int right) {
            return left < right;
        };
        std::priority_queue<int, std::vector<int>, decltype(cmp)> q(cmp);
        for (const auto& s : stones) {
            q.emplace(s);
        }
        while (q.size() > 1) {
            int s1 = q.top();
            q.pop();
            int s2 = q.top();
            q.pop();
            if (s1 != s2) {
                q.emplace(std::abs(s1-s2));
            }
        }
        if (q.empty()) return 0;
        return q.top();
    }
};
