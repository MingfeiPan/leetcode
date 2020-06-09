func twoCitySchedCost(costs [][]int) int {
    var aCost, sizeCost int
    sizeCost = len(costs)
    for _, v := range costs {
        aCost += v[0]
    }
    sort.Slice(costs, func(i int, j int) bool {
        return (costs[i][0] - costs[i][1]) > (costs[j][0] - costs[j][1])
    })
    for i := 0; i < sizeCost / 2; i++ {
        aCost += costs[i][1] - costs[i][0]
    }
    return aCost
}
