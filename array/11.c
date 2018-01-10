
int minNum(int a, int b)
{
    return a < b ? a : b;
}

int maxNum(int a, int b)
{
    return a < b ? b : a;
}
int maxArea(int* height, int heightSize) {
    int result = 0;
    int i = 0;
    int j = heightSize - 1;
    while(i < j)
    {
        int h = minNum(height[i], height[j]);
        result = maxNum(result, (j-i)*h);
        while(height[i] <= h && i < j) i++;
        while(height[j] <= h && i < j) j--;
    }
    return result;
}
