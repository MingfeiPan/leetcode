class Solution {
    public int sumFourDivisors(int[] nums) {
        // 1与自身是2个, 说明如果是4 就正好还多一对, 有超过一对就表示大于4个了
        int ret = 0;
        for (int num : nums) {
            int cur = 0;
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    // 已经有一对值
                    if (cur != 0) {
                        cur = 0;
                        break;
                    }
                    cur = i;
                }
            }
            if (cur > 0 && cur != num / cur) {
                ret += 1 + num + cur + num / cur;
            }
        }
        return ret;
    }
}
