class Solution {
public:
    int minOperations(int n) {
        int ret = 0;
        if (n % 2 == 1) {
            // 如果是奇数个 中间的数就是个数 所有数要经过操作变成中间的数
            int mid_index = (n-1) / 2;
            int mid_value = n;
            for (int i = 0; i < mid_index; i++) {
                ret += n - (2*i+1);
            }
        }else {
            // 偶数个 所有数要变成n
            int mid_index = n/2 - 1;
            int mid_value = n;
            for (int i = 0; i <= mid_index; i++) {
                ret += n - (2*i+1);
            }
        }
        return ret;
    }
};
