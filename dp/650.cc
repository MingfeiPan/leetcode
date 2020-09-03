class Solution {
public:
    int minSteps(int n) {
        if (n == 1) {
            return 0;
        }
        int result = 1001;
        dfs(n, 1, 1, 1, &result);
        return result;
    }
    
private:
    void dfs(int n, int cur_value, int copy, int cur_step, int* result) {
        if (cur_value > n) {
            return;
        }
        if (cur_value == n) {
            *result = min(*result, cur_step);
            return;
        }
        dfs(n, cur_value + copy, copy, cur_step+1, result);
        dfs(n, cur_value*2, cur_value, cur_step+2, result);
    }
};
