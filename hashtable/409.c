//有偶数的字符都可以自己组成回文, 所以统计出偶数的数量再至多加一个单字符就是构成回文的字符数量
int longestPalindrome(char* s) {
    int set[255] = {0};
    int length = strlen(s);
    int i;
    int result = 0;
    for(i = 0; i < length; i++)
    {
        set[s[i]]++;
        if(set[s[i]] % 2 == 0) result += 2;
    }
    if(result == length) return result;
    return result + 1;
    
}
