class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int odd_sum = 0, even_sum = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if ((i % 2) == 0) {
                even_sum += nums[i];
            } else {
                odd_sum += nums[i];
            }
        }
        int ret = 0;
        int odd_sofar = 0, even_sofar = 0, odd_cur = 0, even_cur = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if ((i % 2) == 0) {
                even_cur = odd_sum - odd_sofar + even_sofar;
                even_sofar += nums[i];
                odd_cur = even_sum - even_sofar + odd_sofar;
                if (odd_cur == even_cur) {
                    ++ret;
                }                
            } else {
                odd_cur = even_sum - even_sofar + odd_sofar;
                odd_sofar += nums[i];
                even_cur = odd_sum - odd_sofar + even_sofar;
                if (odd_cur == even_cur) {
                    ++ret;
                }                
            } 
        }
        return ret;
    }
};
