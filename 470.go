func rand10() int {
    //Rejection Sampling, value from  2 rand7() can form a range from [0,40] that actually is uniformed
    var value int
    for {
        value = (rand7()-1) * 7 + rand7()
        if value <= 40 {
            break
        }
    }
    return 1 + (value - 1) % 10
    
}
