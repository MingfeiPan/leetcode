class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        std::unordered_map<int, int> m;
        for (const auto& i : digits) {
            m[i] += 1;
        }
        std::vector<std::vector<int>> ret;
        std::vector<int> cur;
        recur(ret, cur, m, 3);
        std::vector<int> outputs;
        for (const auto& v : ret) {
            int ret = 0;
            for (const auto& i : v) {
                ret = ret * 10 + i;
            }
            outputs.emplace_back(std::move(ret));
        }
        std::sort(outputs.begin(), outputs.end());
        return outputs;
    }
private:
    void recur(std::vector<std::vector<int>>& ret, std::vector<int>& cur, std::unordered_map<int, int>& m, int size) {
        if (cur.size() == size) {
            if (cur[2] % 2 == 0)
                ret.emplace_back(cur);
            return;
        }
        for (auto&& item : m) {
            if (item.first == 0 && cur.size() == 0)
                continue;
            if (item.second == 0)
                continue;
            cur.emplace_back(item.first);
            --item.second;
            recur(ret, cur, m, size);
            ++item.second;
            cur.pop_back();
        }
    }
};
