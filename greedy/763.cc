class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26];
        std::vector<int> ret;
        for (int i = 0; i < 26; i++) {
            last[i] = 0;
        }
        for (int i = 0; i < S.size(); i++) {
            last[S[i]-'a'] = i;
        }             
        int start = 0, end = 0;
        for (int i = 0; i < S.size(); i++) {
            end = max(end, last[S[i]-'a']);
            if (i == end) {
                // i iter to end
                ret.push_back(i-start+1);
                start = i+1;
            }
        }
        return ret;
    }
};
