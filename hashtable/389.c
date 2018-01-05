//还是利用xor的特性
char findTheDifference(char* s, char* t) {
    int lens = strlen(s);
    int lent = strlen(t);
    int i;
    char result = s[0];
    for(i = 1; i < lens; i++)
    {
        result = result ^ s[i];
    }
    for(i = 0; i < lent; i++)
    {
        result = result ^ t[i];
    }
    return result;
}
