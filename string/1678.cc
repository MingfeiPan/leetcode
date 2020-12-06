class Solution {
public:
    string interpret(string command) {
        std::string ret = "";
        int index = 0;
        while (index < command.size()) {
            if (command[index] == '(') {
                if (command[index+1] == ')') {
                    ret += 'o';
                    index += 2;
                } else {
                    ret += "al";
                    index += 4;
                }
            } else {
                ret += 'G';
                ++index;
            }
        }
        return ret;
    }
};
