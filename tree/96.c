//catalan数的应用 形如f(n) = f(n-1) + f(n-2)f(1) + f(n-3)f(2) + … + f(1)f(n-2) + f(n-1)的特征结构

int numTrees(int n) {
    int a = n+1;
    int b = n;
    long ret = 1;
    for(int i = 1; i <= b; i++)
    {
        ret = ret * a;
        ret = ret / i;
        a++;
    }
    return ret / (n+1);
}
