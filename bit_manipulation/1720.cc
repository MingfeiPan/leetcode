class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        std::vector<int> ret(encoded.size()+1, first);
        for (int i = 0; i < encoded.size(); ++i) {
            ret[i+1] = ret[i] ^ encoded[i];
        }
        return ret;
    }
};
