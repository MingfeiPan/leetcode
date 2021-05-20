class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        std::vector<std::vector<std::string>> ret;
        std::unordered_map<std::string, std::vector<std::string>> m;
        for (const auto &path : paths) {
            std::string dir = "";
            int index = 0, length = path.size();
            while (index < length && path[index] != ' ') {
                dir += path[index];
                ++index;
            }
            ++index;
            std::string file = "";
            std::string content = "";            
            while (index < length) {
                std::string file = "";
                std::string content = ""; 
                while (index < length && path[index] != '(') {
                    file += path[index];
                    ++index;
                }
                ++index;
                while (index < length && path[index] != ')') {
                    content += path[index];
                    ++index;
                }
                ++index;
                auto iter = m.find(content);
                if (iter == m.end()) {
                    std::vector<std::string> temp = {dir + "/" + file};
                    m[content] = temp;
                } else {
                    iter->second.emplace_back(dir + "/" + file);
                }
                ++index;
            }
        }
        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            if (iter->second.size() >= 2)
                ret.emplace_back(iter->second);
        }
        return ret;
    }
};
