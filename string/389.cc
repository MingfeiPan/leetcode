class Solution {
public:
    char findTheDifference(string s, string t) {
        int total = 0;
        for (const auto& c : s) {
            total -= c - 'a';
        }
        for (const auto& c : t) {
            total += c - 'a';
        }
        return total + 'a';
    }
};
