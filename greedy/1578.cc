class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ret = 0;
        int group_cost = cost[0];
        int max_cost = cost[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i-1]) {
                ret += group_cost - max_cost;
                group_cost = 0;
                max_cost = 0;
            }
            group_cost += cost[i];
            max_cost = max(max_cost, cost[i]);
        }
        ret += group_cost - max_cost;
        return ret;
    }
};
