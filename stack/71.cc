class Solution {
public:
    string simplifyPath(string path) {
        std::stack<std::string> s;
        std::string temp;
        bool in = false;
        for (const auto& c : path) {
            if (c == '/') {
                if (!temp.empty()) {
                    if (temp == "..") {
                        if (!s.empty()) s.pop();
                    } else if (temp != ".") {
                        s.emplace(temp);
                    } 
                    temp = "";
                }   
            } else {
                temp += c;
            } 
        }
        if (!temp.empty()) {
            if (temp == "..") {
                if (!s.empty()) s.pop();
            } else if (temp != ".") {
                s.emplace(temp);
            } 
            temp = "";
        }  
        if (s.empty()) return "/";
        std::string ret;
        while (!s.empty()) {
            ret = "/"+ s.top() + ret;
            s.pop();
        }
        return ret;
    }
};
