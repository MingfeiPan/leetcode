//注意转换关系 ret = ret * 10 + x % 10

int reverse(int x) {
    long ret = 0;
    while(x != 0)
    {
        ret = ret * 10 + x % 10;
        x = x / 10;
        if(ret < INT_MIN || ret > INT_MAX) return 0;
    }
    return ret;
}
