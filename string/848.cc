class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int64_t accu = 0;
        for (int i = s.size()-1; i >= 0; --i) {
            accu += shifts[i];
            int64_t init = s[i] - 'a';
            init += accu;
            init %= 26;
            s[i] = 'a' + int(init);
        }
        return s;
    }
};
