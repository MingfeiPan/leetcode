class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.size() <= 1)
            return "";
        bool flag = false;
        for (int i = 0, j = palindrome.size()-1; i < j; ++i, --j) {
            if (flag)
                break;
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                flag = true;
            }
        }
        if (!flag) {
            palindrome[palindrome.size()-1] = palindrome[palindrome.size()-1] + 1;
        }
        return palindrome;
    }
};
