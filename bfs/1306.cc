class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr.empty())
            return false;
        std::queue<int> q_;
        q_.emplace(start);
        std::vector<int> check(arr.size(), 0);
        while (!q_.empty()) {
            int cur = q_.front();
            q_.pop();
            if (arr[cur] == 0)
                return true;
            if (check[cur] > 0)
                continue;
            check[cur] = 1;
            if ((cur - arr[cur]) >= 0 && (cur - arr[cur]) < arr.size() && check[cur - arr[cur]] == 0) {
                q_.emplace(cur - arr[cur]);
            }
            if ((cur + arr[cur]) >= 0 && (cur + arr[cur]) < arr.size() && check[cur + arr[cur]] == 0) {
                q_.emplace(cur + arr[cur]);
            }            
        }
        return false;
    }
};
