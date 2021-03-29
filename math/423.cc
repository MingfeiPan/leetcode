class Solution {
public:
    string originalDigits(string s) {
        // zero two four five three seven six eight nine one 按此顺序都是单独依赖
        std::unordered_map<char, int> table;
        for (const auto &c : s) {
            auto iter = table.find(c);
            if (iter == table.end()) {
                table.emplace(c, 1);
            } else {
                ++iter->second;
            }
        }
        
        std::vector<int> l(10, 0);
        auto zeroiter = table.find('z');
        if (zeroiter != table.end()) {
            l[0] = zeroiter->second;
            table['e'] -= zeroiter->second;
            table['r'] -= zeroiter->second;
            table['o'] -= zeroiter->second;
        }
        auto twoiter = table.find('w');
        if (twoiter != table.end()) {
            l[2] = twoiter->second;
            table['t'] -= twoiter->second;
            table['o'] -= twoiter->second;
        }
        auto fouriter = table.find('u');
        if (fouriter != table.end()) {
            l[4] = fouriter->second;
            table['f'] -= fouriter->second;
            table['o'] -= fouriter->second;
            table['r'] -= fouriter->second;
        }   
        auto fiveiter = table.find('f');
        if (fiveiter != table.end()) {
            l[5] = fiveiter->second;
            table['i'] -= fiveiter->second;
            table['v'] -= fiveiter->second;
            table['e'] -= fiveiter->second;
        }  
        auto threeiter = table.find('r');
        if (threeiter != table.end()) {
            l[3] = threeiter->second;
            table['t'] -= threeiter->second;
            table['h'] -= threeiter->second;
            table['e'] -= threeiter->second * 2;
        }   
        auto seveniter = table.find('v');
        if (seveniter != table.end()) {
            l[7] = seveniter->second;
            table['s'] -= seveniter->second;
            table['n'] -= seveniter->second;
            table['e'] -= seveniter->second * 2;
        }  
        auto sixiter = table.find('x');
        if (sixiter != table.end()) {
            l[6] = sixiter->second;
            table['s'] -= sixiter->second;
            table['i'] -= sixiter->second;
        }  
        auto eightiter = table.find('g');
        if (eightiter != table.end()) {
            l[8] = eightiter->second;
            table['e'] -= eightiter->second;
            table['i'] -= eightiter->second;
            table['h'] -= eightiter->second;
            table['t'] -= eightiter->second;
        } 
        auto nineiter = table.find('i');
        if (nineiter != table.end()) {
            l[9] = nineiter->second;
            table['e'] -= nineiter->second;
            table['n'] -= nineiter->second * 2;
        }       
        auto oneiter = table.find('o');
        if (oneiter != table.end()) {
            l[1] = oneiter->second;
        }   
        std::string ret = "";
        std::vector<char> cs = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for (size_t i = 0; i < 10; ++i) {
            if (l[i] > 0) {
                std::string temp(l[i], cs[i]);
                ret += temp;
            }
        }
        return ret;
    }
};
