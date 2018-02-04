int checknum(char c)
{
    switch(c) {
    case 'I':  
        return 1;  
    case 'V':  
        return 5;  
    case 'X':  
        return 10;  
    case 'L':  
        return 50;  
    case 'C':  
        return 100;  
    case 'D':  
        return 500;  
    case 'M':  
        return 1000;  
    default:
        return 0;
    }
}

int romanToInt(char* s) {
    int i;
    int pre = checknum(s[0]);
    int temp = pre;
    int result = 0;
    int cur = 0;
    for(i = 1; s[i] != '\0'; i++)
    {
        cur = checknum(s[i]);
            if(pre == cur) temp += cur; //相等时给当前分段加上当前值
        else if(pre < cur)   //小于时给当前分段减去当前值
        {
            temp = cur - temp;
        }
        else    //大于时, 加到结果并更新当前分段值
        {
            result += temp;
            temp = cur;            
        }
        pre = cur;
    }
    result += temp;
    return result;
}
