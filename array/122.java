class Solution {
    public int maxProfit(int[] prices) {
        int ret = 0;
        for(int i = 0; i < prices.length-1; i++) {
            if (prices[i] < prices[i+1]) {
                ret += prices[i+1] - prices[i];
            }
        }
        return ret;
    }
}
