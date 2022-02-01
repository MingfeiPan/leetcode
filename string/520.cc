class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1) return true;
        if (word[0] < 97) {
            if (word[1] >= 97) {
                for (int i = 2; i < word.size(); ++i) {
                    if (word[i] < 97) return false;
                }
            } else {
                for (int i = 2; i < word.size(); ++i) {
                    if (word[i] >= 97) return false;
                }                
            }
        } else {
            for (int i = 1; i < word.size(); ++i) {
                if (word[i] < 97) return false;
            }
        }
        return true;
    }
};
