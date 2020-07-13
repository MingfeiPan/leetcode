func reverseBits(num uint32) uint32 {
    ret := int(num)
    l := make([]int, 0)
    for ret > 0 {
        l = append(l, ret % 2)
        ret = ret / 2
    }

    for len(l) < 32 {
        l = append(l, 0)
    }
    accu := 1

    for i := len(l)-1; i >= 0; i-- {
        ret += accu * l[i]
        accu *= 2
    }
    return uint32(ret)
}
