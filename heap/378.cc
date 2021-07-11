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

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto cmp = [](int a, int b) {
            return a > b;       
        };
        std::priority_queue<int, std::vector<int>, decltype(cmp)> q(cmp);
        for (const auto& line : matrix) {
            for (const auto& num : line) {
                q.emplace(num);
            } 
        }
        while (k > 1) {
            q.pop();
            --k;
        }
        return q.top();
    }
};
