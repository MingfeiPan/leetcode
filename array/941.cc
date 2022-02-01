class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        int i = 0, j = arr.size()-1;
        // first half
        while (i < (arr.size()-1) && arr[i] < arr[i+1])
            ++i;
        // second half
        while (j > 0 && arr[j] < arr[j-1])
            --j;
        if (i == 0 || j == (arr.size()-1)) return false;
        return i == j;
    }
};
