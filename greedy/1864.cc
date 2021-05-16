class Solution {
public:
    int minSwaps(string s) {
        int ones = 0, zeros = 0;
        for (const auto& c : s) {
            if (c == '0') {
                ++zeros;
            } else {
                ++ones;
            }
        }
        if (std::abs(ones - zeros) >= 2)
            return -1;
        if (ones > zeros) {
            return counting(s, '1');
        } 
        if (zeros > ones) {
            return counting(s, '0');
        }
        return std::min(counting(s, '0'), counting(s, '1'));
    }
private:
    int counting(std::string& s, char target) {
        // counting adjacent
        int count = 0;
        for(int i=0; i<s.size(); i+=2) {
            if(s[i] != target) count++;
        }
        return count;

    }
};
