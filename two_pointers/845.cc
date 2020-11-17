class Solution {
public:
    int longestMountain(vector<int>& A) {
        int index = 1, ret = 0;
        while (index < A.size()) {
            int up = 0, down = 0;
            while (index < A.size() && A[index-1] < A[index]) {
                ++index;
                ++up;
            }
            while (index < A.size() && A[index-1] > A[index]) {
                ++index;
                ++down;
            }
            if (up > 0 && down > 0 && (up + down + 1) > ret) {
                ret = up + down + 1;
            }
            while (index < A.size() && A[index-1] == A[index]) {
                ++index;
            }
        }
        return ret;
    }
};
