//should hava a better solution

int cmp(const void* a, const void* b)
{
    return *(int*)a < *(int*)b ? 0 : 1;
}

bool isAnagram(char* s, char* t) {
    int l1 = strlen(s);
    int l2 = strlen(t);
    if(l1 != l2) return false;
    int* arr1 = malloc(sizeof(int)*l1);
    int* arr2 = malloc(sizeof(int)*l2);
    int i;
    for(i = 0; i < l1; i++)
    {
        arr1[i] = s[i];
    }
    for(i = 0; i < l2; i++)
    {
        arr2[i] = t[i];
    }    
    qsort(arr1, l1, sizeof(int), cmp);
    qsort(arr2, l2, sizeof(int), cmp);
    for(i = 0; i < l1; i++)
    {
        if(arr1[i] != arr2[i]) return false;
    }
    return true;
    
}
