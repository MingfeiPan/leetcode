func addStrings(num1 string, num2 string) string {
    var ret string
    var flag bool
    i := len(num1)-1
    j := len(num2)-1
    for i >= 0 || j >= 0 {
        sum := 0
        if i >= 0 {
            sum += int(num1[i] - '0')
            i--
        }
        if j >= 0 {
            sum += int(num2[j] - '0')
            j--
        }
        if flag {
            sum++
        }
        if sum >= 10 {
            flag = true
        }else {
            flag = false
        }
        sum = sum % 10
        ret = string(sum+'0') + ret
    }
    if flag {
        ret = "1" + ret
    }
    return ret
}
