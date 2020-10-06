class Solution {
public:
    int bitwiseComplement(int N) {
        std::vector<char> str;
        if (N == 0) {
            return 1;
        }
        while (N > 0) {
            if (N % 2 == 1) {
                str.emplace_back('1');    
            } else {
                str.emplace_back('0');
            }
            N = N / 2;
        }
        for (auto& c : str) {
            if (c == '1') {
                c = '0';
            } else {
                c = '1';
            }
        }
        int ret = 0;
        int accu = 1;
        for (auto& c : str) {
            if (c == '1') {
                ret += accu;
            }
            accu *= 2;
        }
        return ret;
    }
};
