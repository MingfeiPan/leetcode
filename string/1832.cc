class Solution {
public:
    bool checkIfPangram(string sentence) {
        if (sentence.size() < 26)
            return false;
        std::vector<int> table(26, 0);
        for (const auto & c : sentence) {
            table[c-97] = 1;
        }
        return sum(table) == 26;
    }
private:
    int sum(std::vector<int> &table) {
        int sum = 0;
        for (const auto &i : table) {
            sum += std::move(i);
        }
        return sum;
    }
};
