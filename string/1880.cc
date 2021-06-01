class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return (convert(firstWord) + convert(secondWord)) == convert(targetWord);
    }
private:
    int convert(std::string word) {
        int ret = 0, index = 0;
        while (index < word.size() && word[index] == '0') {
            ++index;
        }
        while (index < word.size()) {
            ret *= 10;
            ret += word[index] - 'a';
            ++index;
        }
        return ret;
    }
};
