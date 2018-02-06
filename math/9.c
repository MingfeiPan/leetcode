int reverse(int x)
{
    int re = 0;
    while(x)
    {
        re = re * 10 + x % 10;
        x = x / 10;
    }
    return re;
}
bool isPalindrome(int x) {
    if(x < 0) return false;
    if(x == 0) return true;
    
    return reverse(x) == x;
}
