
char* convert(char* s, int numRows) {
    if(numRows == 1) return s;
    int len = strlen(s);
    char* ret = malloc(sizeof(char)*(len+1));
    int n;
    int m;
    int retpos = 0;
    for(int i = 0; i < numRows; i++)
    {
        n = (numRows - i - 1) * 2;
        m = i * 2;
        int pos = i;
        if(pos < len) ret[retpos++] = s[pos];
        while(true)
        {
            pos += n;
            if(len <= pos) break;
            if(n) ret[retpos++] = s[pos];
            pos += m;
            if(len <= pos) break;
            if(m) ret[retpos++] = s[pos];
        }
    }
    ret[len] = '\0';
    return ret;

}
