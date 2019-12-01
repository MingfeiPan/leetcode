func numOfBurgers(tomatoSlices int, cheeseSlices int) []int {
    extra := tomatoSlices - cheeseSlices * 2
    
    if extra < 0 || extra % 2 != 0 {
        return []int{}
    }
    jumbo := extra / 2
    small := cheeseSlices - jumbo
    if small < 0 {
        return []int{}
    }
    return []int{jumbo, small}
}
