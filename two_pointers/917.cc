class Solution {
public:
    string reverseOnlyLetters(string s) {
        for (int i = 0, j = s.size()-1; i < j;) {
            while (i < j && (s[i] < 65 || s[i] > 90 && s[i] < 97))
                ++i;
            while (i < j && (s[j] < 65 || s[j] > 90 && s[j] < 97))
                --j;
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            ++i;
            --j;
        }
        return s;
    }
};
