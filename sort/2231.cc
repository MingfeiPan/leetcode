class Solution {
public:
    int largestInteger(int num) {
        std::vector<int> odd;
        std::vector<int> even;
        int dummy = num;
        while (dummy > 0) {
            int temp = dummy % 10;
            dummy = dummy / 10;
            if (temp % 2 == 0) even.emplace_back(temp);
            else odd.emplace_back(temp);
        }
        std::sort(odd.begin(), odd.end());
        std::sort(even.begin(), even.end());
        std::vector<int> ret;
        int index_odd = 0, index_even = 0;
        while (num > 0) {
            int temp = num % 10;
            num = num / 10;
            if (temp % 2 == 0) ret.emplace_back(even[index_even++]);
            else ret.emplace_back(odd[index_odd++]);
        }
        
        for (int i = ret.size()-1; i >= 0; --i) {
            num = num * 10 + ret[i];
        }
        return num;
    }
};
