class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        std::string output;
        output.reserve(s.size() + spaces.size());
        int start = 0, end = 0;
        
        for (const auto& i : spaces) {
            end = i;
            output += s.substr(start, end-start) + " ";
            start = i;
        }
        output += s.substr(start);
        return output;
    }
};
