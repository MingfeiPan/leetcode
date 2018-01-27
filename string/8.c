//bag case
int myAtoi(char* str) {
    long result = 0;
    int flag1 = 0;
    int flag2 = 1;
    while(isspace(*str)) str++;
    
    if(*str=='-' || *str=='+')
    {
        if(*str == '-') flag2 = -1;
        if(*str == '+') flag1  = 1;
        str++;
    }
    if(*str <= 'z' && 'a' <= *str) return 0;
    while(*str <= '9' && '0' <= *str && result <= INT_MAX)
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    if(INT_MAX < result)
    {
        if(flag2 == -1) return INT_MIN;
        else return INT_MAX;
    }
    if(flag2 == -1) return result * -1;
    return result;
}
