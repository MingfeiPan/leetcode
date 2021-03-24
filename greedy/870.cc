class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        std::multiset<int> s(A.begin(), A.end());
        for (size_t i = 0; i < A.size(); ++i) {
            auto it = s.upper_bound(B[i]);
            if (it == s.end()) {
                it = s.begin();
            }
            A[i] = *it;
            s.erase(it);
        }
        return A;
    }
};
