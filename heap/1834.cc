class Solution {
struct Item {
    int index;
    int start;
    int duration;
};
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (size_t i = 0; i < tasks.size(); ++i) {
            tasks[i].emplace_back(i);
        }
        std::sort(tasks.begin(), tasks.end(), [](std::vector<int> &a, std::vector<int> &b){
            return a[0] < b[0];
        });
        auto compare = [](std::vector<int> &v1, std::vector<int> &v2) {
            if (v1[1] == v2[1])
                return v1[2] > v2[2];
            return v1[1] > v2[1];
        };
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(compare)> pq(compare);
        
        int i = 0;
        int end_time = 0;
        std::vector<int> ret;
        while (i < tasks.size()) {
            if (pq.empty()) {
                int start_time = tasks[i][0];
                while (i < tasks.size() && start_time == tasks[i][0]) {
                    pq.emplace(tasks[i]);
                    ++i;
                }
            } else {
                auto cur = pq.top();
                ret.emplace_back(cur[2]);
                pq.pop();
                
                end_time = std::max(end_time, cur[0]) + cur[1];
                while (i < tasks.size() && tasks[i][0] <= end_time) {
                    pq.emplace(tasks[i]);
                    ++i;
                }
            }
        }
        while (!pq.empty()) {
            auto cur = pq.top();
            ret.emplace_back(cur[2]);
            pq.pop();
        }
        return ret;
    }
};
