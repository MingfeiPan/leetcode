class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        std::vector<std::string> ret;
        std::unordered_map<char, int> checkA;
        std::unordered_map<char, int> checkB;
        bool flag = false;
        for (const auto &word : B) {
            for (const auto &c : word) {
                auto iter = checkB.find(c);
                if (iter == checkB.end()) {
                    checkB[c] = 1;
                } else {
                    ++iter->second;
                }
            }
        }

        for (const auto &word : A) {
            checkA.clear();
            flag = false;
            for (const auto &c : word) {
                auto iter = checkA.find(c);
                if (iter != checkA.end()) {
                    ++iter->second;
                } else {
                    checkA[c] = 1;
                }
            }
            for (auto iter = checkB.begin(); iter != checkB.end(); ++iter) {
                auto iterA = checkA.find(iter->first);
                if (iterA == checkA.end() || iterA->second == 0) {
                    flag = true;
                    break;
                }
                --iterA->second;
            }
            if (!flag) {
                ret.emplace_back(word);
            }
        }
        return ret;
    }
};
