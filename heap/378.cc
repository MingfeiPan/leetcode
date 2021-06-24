class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto comp = [](int a, int b) {
            return a < b;
        };
        std::priority_queue<int, std::vector<int>, decltype(comp)> q(comp);
        for (const auto& v: matrix) {
            for (const auto& i : v) {
                if (q.size() < k) {
                    q.push(i);
                } else {
                    if (q.top() > i) {
                        q.pop();
                        q.push(i);
                    }
                }
            }
        }
        return q.top();
    }
};
