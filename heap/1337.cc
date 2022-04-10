class Solution {
struct Item {
    int count;
    int index;
};
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        std::vector<Item> v;
        for (int i = 0; i < mat.size(); ++i) {
            Item item;
            item.count = std::count(mat[i].begin(), mat[i].end(), 1);
            item.index = i;
            v.emplace_back(std::move(item));
        }
        std::sort(v.begin(), v.end(), [](Item& a, Item& b){
            if (a.count == b.count) return a.index < b.index;
            return a.count < b.count;
        });
        std::vector<int> ret;
        for (const auto& i : v) {
            if (k == 0) break;
            --k;
            ret.emplace_back(std::move(i.index));
        }
        return ret;
    }
};
