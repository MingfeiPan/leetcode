func numWaterBottles(numBottles int, numExchange int) int {
    var ret int
    ret += numBottles
    for numBottles >= numExchange {
        temp := numBottles / numExchange
        ret += temp
        numBottles = numBottles % numExchange + temp
    }
    return ret
}
