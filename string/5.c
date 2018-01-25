//注意返回字符串尾部的结束符'\0'
void findPalindrome(char* s, int start, int end, int* offset, int* maxLen, int length)
{
    while(start >= 0 && end < length && s[start] == s[end])
    {
        start--;
        end++;
    }
    if(*maxLen < end - start - 1)
    {
        *maxLen = end - start - 1;
        *offset =  start + 1;
    }
    
}
char* longestPalindrome(char* s) {
    int length = strlen(s);
    if(length < 2) return s;
    int maxLen = 0;
    int pos;
    for(int i = 0; i < length -1; i++)
    {
        findPalindrome(s, i, i, &pos, &maxLen, length);
        findPalindrome(s, i, i + 1, &pos, &maxLen, length);
    }
    char* result = malloc(sizeof(char)*(maxLen+1));
    strncpy(result, s+pos, maxLen);
    result[maxLen] = '\0';
    return result;
}
