class Solution {
public:
    string reformatNumber(string number) {
        std::string ret = "";
        int counter = 0;
        number.erase(std::remove(number.begin(), number.end(), ' '), number.end());
        number.erase(std::remove(number.begin(), number.end(), '-'), number.end());

        for (int i = 0; i < number.size(); i += 3) {
            if ((number.size()-i) == 4) {
                ret += number.substr(i, 2) + '-' + number.substr(i+2, 2);
                break;
            } else {
                ret += number.substr(i, 3);
                if ((i+3) != (number.size()) && (i+2) != (number.size()) ) {
                    ret += '-';    
                }
            }
        }
        
        return ret;
    }
};
