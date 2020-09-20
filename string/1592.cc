class Solution {
public:
    string reorderSpaces(string text) {
        if (text.size() <= 1) {
            return text;
        }
        int space_count = 0;
        int word_count = 0;
        std::vector<std::string> words;
        bool init_space = false;
        int start_index = 0;
        if (text[0] == ' ') {
            space_count++;
            init_space = true;
        }
        for (int i = 1; i < text.size(); i++) {
            if (text[i] == ' ') {
                space_count++;
            }
            if (text[i] != ' ' && text[i-1] == ' ') {
                start_index = i;
            }
            if (text[i] == ' ' && text[i-1] != ' ') {
                word_count++;
                words.emplace_back(text.substr(start_index, i - start_index));
            }
            if (text[i] != ' ' && (i+1) == text.size()) {
                word_count++;
                words.emplace_back(text.substr(start_index, i - start_index+1));                
            }
        }
        int left = 0;
        int count = 0;
        if (word_count == 1) {
            left = space_count;
            count = 0;
        } else {
            left = space_count % (word_count-1);
            count = space_count / (word_count-1);            
        }
        std::string ret = "";
        for (int i = 0; i < words.size(); i++) {
            ret += words[i];
            if ((i+1) == words.size()) {
                break;
            }
            for (int i = 0; i < count; i++) {
                ret += " ";
            }
        }
        while (left > 0) {
            ret += " ";
            left--;
        }
        return ret;
    }
};
