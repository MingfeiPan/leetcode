class Solution {
public:
    bool halvesAreAlike(string s) {
        int count = 0;
        std::unordered_set vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (int i = 0; i < s.size()/2; ++i) {
            auto iter = vowels.find(s[i]);
            if (iter != vowels.end())
                ++count;
        }
        for (int i = s.size()/2; i < s.size(); ++i) {
            auto iter = vowels.find(s[i]);
            if (iter != vowels.end())
                --count;
        }
        return count == 0;
    }
};
