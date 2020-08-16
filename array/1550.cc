class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() < 3) {
            return false;
        }
        for (int i = 0; i < arr.size()-2;) {
            if (arr[i] % 2 == 0) {
                i++;
            }else if (arr[i+1] % 2 == 0) {
                i += 2;
            }else if (arr[i+2] % 2 == 0) {
                i += 3;
            }else {
                return true;
            }
        }
        return false;
    }
};
