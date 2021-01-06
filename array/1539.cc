class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int index = 0, value = 1;
        while (index < arr.size()) {
            if (k == 0) {
                return value-1;
            }
            if (arr[index] != value) {
                --k;
            } else {
                ++index;
            }
            ++value;
        }
        while (k > 0) {
            ++value;
            --k;
        }
        return value-1;
    }
};
