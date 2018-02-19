//top-k 问题的O(n)实现, bfprt algorithm
#include <stdio.h>

int bfprt(int*, int, int, int);

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;		
}

int insertsort(int* arr, int left, int right)
{
	int len = right - left + 1;
	for(int i = 0; i < len; i++)
	{
		for(int j = i; j > 0; j--)
		{
			if(arr[j+left] < arr[j-1+left]) swap(&arr[j+left], &arr[j-1+left]);
		}
	}
	return (right - left) / 2 + left;
}

int getpivot(int* arr, int left, int right)
{
	if((right - left) < 5)
		return insertsort(arr, left, right);
	int flag = left - 1;
	int index;
	for(int i = left; i + 4 <= right; i+= 5)
	{
		index = insertsort(arr, i, i+4);
		swap(&arr[++flag], &arr[index]);
	}
	return bfprt(arr, left, flag, ((flag - left + 1) / 2) + 1);
}

int partition(int* arr, int left, int right, int pivot)
{
	swap(&arr[pivot], &arr[right]);
	int index = left;
	
	for(int i = left; i < right; i++)
	{
		if(arr[i] > arr[right]){
			// if(index != i){
			// 	swap(&arr[index++], &arr[i]);
			// }
			// else{	
			// 	index++;
			// }
			swap(&arr[index++], &arr[i]);
		}
	}
	swap(&arr[index], &arr[right]);
	return index;
}

int bfprt(int* arr, int left, int right, int k)
{
	int pivot = getpivot(arr, left, right);	
	int index = partition(arr, left, right, pivot);
	int ret = index - left + 1;

	if(ret == k) 
		return index;
	else if( ret > k)
		return bfprt(arr, left, index - 1, k);
	else
		return bfprt(arr, index + 1, right, k - ret);
}

int main()
{
	int arr[] = {921,22,343,23,45,666,234,75,234,61,311};
	int len = sizeof(arr) / sizeof(int);
	int ret = bfprt(arr, 0, len-1, 5);	
	for(int i = 0; i < len; i++)
		printf("%d\n", arr[i]);
	return 0;
}

