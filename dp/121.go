func maxProfit(prices []int) int {
    
    if len(prices) == 0 {
        return 0
    }
    ret := 0
    curlow := prices[0]
    for i := 1; i < len(prices); i++ {
        if prices[i] - curlow > ret {
            ret = prices[i] - curlow
        }
        if prices[i] < curlow {
            curlow = prices[i]
        }
    }
    return ret
}
