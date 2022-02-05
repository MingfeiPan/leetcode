class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        std::unordered_map<int, int> pos;
        pos[0] = -1;
        int count = 0, ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ++count;
            } else {
                --count;
            }
            auto iter = pos.find(count);
            if (iter != pos.end()) {
                ret = std::max(ret, i - iter->second);    
            } else {
                pos[count] = i;
            }
        }
        return ret;
    }
};
