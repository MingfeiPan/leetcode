class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0, cur_height = 0, i = 0, j = height.size()-1;
        while (i < j) {
            cur_height = std::min(height[i], height[j]);
            ret = std::max(ret, (j-i)*cur_height);
            while (height[i] <= cur_height && i < j)
                ++i;
            while (height[j] <= cur_height && i < j)
                --j;
        }
        return ret;
    }
};
