int firstUniqChar(char* s) {
    int set[255] = {0};
    int length = strlen(s);
    int i;
    for(i = 0; i < length; i++)
    {
        set[s[i]]++;
    }
    for(i = 0; i < length; i++)
    {
        if(set[s[i]] == 1) return i; 
    }
    return -1;
}
