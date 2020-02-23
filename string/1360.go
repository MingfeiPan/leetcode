func daysBetweenDates(date1 string, date2 string) int {
    data1arr := strings.Split(date1, "-")
    data2arr := strings.Split(date2, "-")
    monthMap := map[int]int {
        1: 31,
        2: 28,
        3: 31,
        4: 30,
        5: 31,
        6: 30,
        7: 31,
        8: 31,
        9: 30,
        10: 31,
        11: 30,
        12: 31,
    }
    var startyear, endyear, startdays, enddays, ret int
    startyear, _ = strconv.Atoi(data1arr[0])
    intmonthdata1, _ := strconv.Atoi(data1arr[1])
    intdaydata1, _ := strconv.Atoi(data1arr[2])
    
    endyear, _ = strconv.Atoi(data2arr[0])
    intmonthdata2, _ := strconv.Atoi(data2arr[1])
    intdaydata2, _ := strconv.Atoi(data2arr[2])
    if startyear > endyear {
        startyear, endyear =  endyear, startyear
        intmonthdata1, intmonthdata2 = intmonthdata2, intmonthdata1
        intdaydata1, intdaydata2 = intdaydata2, intdaydata1 
        
    }
    for i := startyear; i < endyear; i++ {
        if i % 4 == 0 {
            ret += 366
        }else {
            ret += 365
        }
    }
    
    for i := 1; i < intmonthdata1; i++ {
        if i == 2 && startyear % 4 == 0 && endyear % 100 != 0 {
            startdays += 29
            continue
        }
        startdays += monthMap[i]
    }
    startdays += intdaydata1

    for i := 1; i < intmonthdata2; i++ {
        if i == 2 && endyear % 4 == 0 && endyear % 100 != 0 {
            enddays += 29
            continue
        }
        enddays += monthMap[i]
    }

    enddays += intdaydata2   
    if ret == 0 {
        if startdays > enddays {
            return startdays - enddays
        }
    }
    return ret - startdays + enddays
    
}
