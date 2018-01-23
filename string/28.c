//brute force
int strStr(char* haystack, char* needle) {
    int m = strlen(haystack);
    int n = strlen(needle);
    int len = m - n;
    char* p;
    char* q;
    for(int i = 0; i <= len; i++)
    {
        p = haystack + i;
        q = needle;
        while(*q && *q == *p)
        {
            p++;
            q++;
        }
        if(*q == 0) return i;
    }
    return -1;
}
