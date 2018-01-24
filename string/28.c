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


//cmp in O(n)
int* buildNext(char* tar)
{
	int m = strlen(tar);
	int j = 0;
	int* next = (int*)malloc(sizeof(int)*m);
	int t = next[0] = -1;
	while(j < m - 1)
	{
		if( t < 0 || tar[j] == tar[t])
		{
			next[++j] = ++t;
		}
		else
		{
			t = next[t];
		}
	}
	return next;
}

int strStr(char* haystack, char* needle)
{
	int* next = buildNext(needle);
	int n = strlen(haystack);
	int i = 0;
	int m = strlen(needle);
	int j = 0;
	while(j < m && i < n)
	{
		if(j < 0 || needle[j] == haystack[i])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	free(next);
    int ret = i - j;
    if(n < ret + m) return -1;
    else return ret;
}
