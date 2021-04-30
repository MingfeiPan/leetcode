class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        auto cmp = [](int a, int b) {
            return a < b;
        };
        std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
        int index = 0;
        for (; index < (heights.size()-1); ++index) {
            int drop = heights[index+1] - heights[index];
            if (drop <= 0)
                continue;
            if (drop <= bricks) {
                bricks -= drop;
                pq.emplace(drop);
            } else if (!pq.empty() && ladders > 0 && pq.top() > drop) {
                bricks += pq.top() - drop;
                pq.pop();
                pq.emplace(drop);
                --ladders;
            } else if (ladders > 0) {
                --ladders;
            } else {
                break;
            }
        }
        return index;
    }
};
