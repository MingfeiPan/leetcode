bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if(flowerbedSize == 1 && flowerbed[0] == 0) return true;
    if(flowerbed[0] == 0 && flowerbed[1] == 0)
    {
        flowerbed[0] = 1;
        n--;
    }
    if(flowerbed[flowerbedSize-1] == 0 && flowerbed[flowerbedSize-2] == 0)
    {
        flowerbed[flowerbedSize-1] = 1;
        n--;
    }
    for( int i = 1; i < flowerbedSize-1; i++)
    {
        if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0)
        {
            flowerbed[i] = 1;
            n--;
        }
    }
    return n <= 0;
} 
