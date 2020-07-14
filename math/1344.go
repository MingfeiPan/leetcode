func angleClock(hour int, minutes int) float64 {
    // 小时按照刻度 一个小时30度, 每一个30度 可以分成60分 所以 一分钟0.5度
    var hourDegree, minDegree float64
    hourDegree = float64((hour % 12) * 30) + float64(minutes) * 0.5
    // 一分钟6度
    minDegree = float64(minutes * 6) 
    if minDegree < hourDegree {
        return min(hourDegree - minDegree, 360 - (hourDegree - minDegree))
    }else {
        return min(minDegree - hourDegree, 360 - (minDegree - hourDegree))
    }
    return -1
}

func min(a float64, b float64) float64 {
    if a < b {
        return a
    }else {
        return b
    }
}

