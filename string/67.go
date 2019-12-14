func addBinary(a string, b string) string {
    var flag bool
    var ret string
    var i, j int
    for i, j = len(a)-1, len(b)-1; i >= 0 && j >= 0; i, j = i-1, j-1 {
        if flag {
            if a[i] == '1' && b[j] == '1' {
                ret = "1" + ret
            }else if a[i] == '0' && b[j] == '0' {
                ret = "1" + ret
                flag = false
            }else {
                ret = "0" + ret
            }
        }else {
            if a[i] == '1' && b[j] == '1' {
                ret = "0" + ret
                flag = true
            }else if a[i] == '0' && b[j] == '0' {
                ret = "0" + ret
            }else {
                ret = "1" + ret
            }            
        }
    }
    for i >= 0 {
        if flag {
            if a[i] == '1' {
                ret = "0" + ret
            }else {
                ret = "1" + ret
                flag = false
            }
        }else {
            if a[i] == '1' {
                ret = "1" + ret
            }else {
                ret = "0" + ret
            }
        }
        i--
    }
    for j >= 0 {
        if flag {
            if b[j] == '1' {
                ret = "0" + ret
            }else {
                ret = "1" + ret
                flag = false
            }
        }else {
            if b[j] == '1' {
                ret = "1" + ret
            }else {
                ret = "0" + ret
            }
        }
        j--
    }    
    if flag {
        ret = "1" + ret
    }
    return ret
}
