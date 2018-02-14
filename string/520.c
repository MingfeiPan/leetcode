//compare in ascii
bool detectCapitalUse(char* word) {
    char compare = '`';
    int flag = 0;
    int countUpper = 0;
    int len = strlen(word);
    if(word[0] > compare)
        flag = 1;
    else
        countUpper++;    
    for(int i = 1; i < len; i++)
    {
        
        if(word[i] < compare && flag == 1) 
            return false;
        if(word[i] < compare && flag == 0)
            countUpper++;
    }

    if(countUpper == 0 && flag == 1) return true;
    if(countUpper == len && flag == 0) return true;
    if(countUpper == 1 && flag == 0) return true;
    return false;
    
}
