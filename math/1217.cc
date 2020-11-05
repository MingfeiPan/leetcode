class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        // 相隔为2的怎么移动 cost 都是0, 只需要考虑相隔为1的移动, odd even 选一个较小值
        for (const auto& i: position) {
            if (i % 2 == 0) {
                ++even;
            } else {
                ++odd;
            }
        }
        if (odd < even) {
            return odd;
        }
        return even;
    }
};
