class Solution {
public:
    string modifyString(string s) {
        for (size_t i = 0; i < s.size(); i++) {
            std::cout << s << std::endl;
            if (s[i] == '?') {
                if (i == 0) {
                    if ((i+1) < s.size()) {
                        s[i] = s[i+1]+1;
                        if (s[i] >= 'z' || s[i] < 'a') {
                            s[i] = 'a';
                        }
                        while (s[i] == s[i+1]) {
                            s[i]++;
                            if (s[i] >= 'z') {
                                s[i] = 'a';
                            }                            
                        }                            
                    }else {
                        s[i] = 'a';
                    }
                }else if (i == s.size()-1) {
                    if ((i-1) >= 0) {
                        s[i] = s[i-1]+1;
                        if (s[i] >= 'z' || s[i] < 'a') {
                            s[i] = 'a';
                        }
                        while (s[i] == s[i-1]) {
                            s[i]++;
                            if (s[i] >= 'z' || s[i] < 'a') {
                                s[i] = 'a';
                            }                            
                        }                           
                    }else {
                        s[i] = 'a';
                    }               
                }else {
                    s[i] = s[i-1]+1;
                    if (s[i] >= 'z' || s[i] < 'a') {
                        s[i] = 'a';
                    }                    
                    while (s[i] == s[i-1] || s[i] == s[i+1]) {
                        s[i]++;
                        if (s[i] >= 'z' || s[i] < 'a') {
                            s[i] = 'a';
                        }                        
                    }
                }
            }
        }
        return s;
    }
};
