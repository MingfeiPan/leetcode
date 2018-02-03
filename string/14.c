//利用strs[0]做基准, 与之后的string进行比较, 发生不匹配就跳出
char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0 || strlen(strs[0]) == 0) return "";
    if(strsSize == 1) return strs[0];
    int prefixindex = 0;
    int flag = true;
    while(flag)
    {
        for(int i = 1; i < strsSize; i++)
        {
            if(strs[0][prefixindex] == strs[i][prefixindex]) continue;
            else
            {
                flag = false;
                break;
            }
        }
        prefixindex++;
    }
    
    if(prefixindex == 0) return "";
    else
    {
        char* ret = malloc(sizeof(char)*(prefixindex));
        strncpy(ret, strs[0], prefixindex - 1);
        ret[prefixindex - 1] = '\0';
        return ret;
    }
}
