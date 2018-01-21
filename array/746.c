//simple dp
int min(int a, int b){
    return a < b ? a : b;
}

int minCostClimbingStairs(int* cost, int costSize) {
    int* result = malloc(sizeof(int)*costSize);
    result[0] = cost[0];
    result[1] = cost[1];
    for(int i = 2; i < costSize; i++)
    {
        result[i] = cost[i] + min(result[i-2], result[i-1]);   
    }
    return min(result[costSize-1], result[costSize-2]);
}
