class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ret = 0;
        std::vector<int> lines;
        for (const auto& s : bank) {
            lines.emplace_back(counter(s));
        }
        for (int i = 0; i < lines.size();) {
            if (lines[i] == 0) {
                ++i;
                continue;
            }
            for (int j = i+1; j < lines.size(); ++j) {
                if (lines[j] == 0) {
                    if ((j+1) == lines.size())
                        i = j;
                    continue;
                }
                ret += lines[i] * lines[j];
                i = j;
            }
            if ((i+1) == lines.size()) break;
        }
        return ret;
    }
private:
    int counter(const std::string& s) {
        int ret = 0;
        for (const auto& c : s) {
            if (c == '1') ++ret;
        }
        return ret;
    }
};
