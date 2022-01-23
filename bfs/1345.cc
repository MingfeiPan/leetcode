class Solution {
struct Item {
    int index;
    int step;
};
public:
    int minJumps(vector<int>& arr) {
        std::vector<int> reached(arr.size(), 0);
        std::unordered_map<int, std::vector<int>> m;
        for (int i = 0; i < arr.size(); ++i) {
            m[arr[i]].emplace_back(i);
        }
        std::queue<Item> q;
        q.push(Item{0, 0});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur.index == (arr.size()-1))
                return cur.step;
            if (reached[cur.index] == 1)
                continue;
            reached[cur.index] = 1;
            if ((cur.index+1) < arr.size() && reached[cur.index+1] == 0)
                q.push(Item{cur.index+1, cur.step+1});
            if ((cur.index-1) >= 0 && reached[cur.index-1] == 0)
                q.push(Item{cur.index-1, cur.step+1});
            for (const auto& i : m[arr[cur.index]]) {
                if (reached[i] == 0)
                    q.push(Item{i, cur.step+1});
            }
            m[arr[cur.index]].clear();
        }
        return arr.size();
    }
};
