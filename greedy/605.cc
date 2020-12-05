class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0, j = 0;
        while (i < flowerbed.size()) {
            while (i < flowerbed.size() && flowerbed[i] == 1) {
                ++i;
            }
            j = i;
            while (j < flowerbed.size() && flowerbed[j] == 0) {
                ++j;
            }
            
            if ((j-i) % 2 == 0) {
                if (i == 0 || j == flowerbed.size()) {
                    n -= (j-i) / 2;
                } else {
                    n -= (j-i) / 2 - 1;
                }
            } else {
                if (i == 0 && j == flowerbed.size()) {
                    n -= (j-i) / 2 + 1;
                } else {
                    n -= (j-i) / 2;    
                }
            }
            if (n <= 0)
                break;
            i = j;
        }
        return n <= 0;
    }
};
