int countSegments(char* s) {
    int count = 0;
    while(*s != '\0'){
        if(*s != ' ' && (*(s+1) == ' ' || *(s+1) == '\0'))
            count++;
        s++;
    }
    return count;
}
