/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* result = (int*)malloc(sizeof(int)*2);
    int index2 = numbersSize - 1;
    int index1 = 0;
    *returnSize = 2;
    while(index1 < index2)
    {
        if(target == (numbers[index1] + numbers[index2]))
        {
            result[0] = index1+1;
            result[1] = index2+1;
            return result;
        }
        while(index1 < index && target < (numbers[index1] + numbers[index2])) index2--;
        while(index1 < index2 && target > (numbers[index1] + numbers[index2])) index1++;
    }
    return result;
}
