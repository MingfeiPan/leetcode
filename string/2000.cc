class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = -1;
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == ch) {
                index = i;
                break;
            }
        }
        if (index == -1)
            return word;
        for (int i = 0; i < index; ++i, --index) {
            char temp = word[i];
            word[i] = word[index];
            word[index] = temp;
        }
        return word;
    }
};
