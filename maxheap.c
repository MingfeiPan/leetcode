#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct maxheap{
	int size;
	int* arr;
} maxheap;

int leftChild(int i)
{
	return (i << 1) + 1;
}

int rightChild(int i)
{
	return (i << 1) + 2;
}

int parent(int i)
{
	return (i - 1) >> 1;
}

maxheap init()
{
	maxheap hp;
	hp.size = 0;
	return hp;
}

void swap(int* h1, int* h2)
{
	int temp = *h1;
	*h1 = *h2;
	*h2 = temp;
}

//上溢
void percolateUp(maxheap* hp, int i)
{
	while(parent(i))
	{
		int j = parent(i);
		if((hp->arr)[i] < (hp->arr)[j]) break;
		swap(&((hp->arr)[i]), &((hp->arr)[i]));
		i = j;
	}
}

void percolateDown(maxheap* hp, int index)
{
	while (index < hp->size)
	{
		int lc = leftChild(index);
		int rc = rightChild(index);
		if(hp->size < lc && hp->size < rc) return;
		else if( lc < hp->size  && hp->size <= rc)
		{
			if((hp->arr)[lc] < (hp->arr)[index]) return;
			else
			{
				swap(&((hp->arr)[index]), &((hp->arr)[lc]));
				index = lc;
			}
		}
		else if(hp->size <= lc  && rc < hp->size)
		{
			if((hp->arr)[rc] < (hp->arr)[index]) return;
			else
			{
				swap(&((hp->arr)[index]), &((hp->arr)[rc]));
				index = rc;
			}
		}
		else
		{
			if((hp->arr)[lc] < (hp->arr)[index] && (hp->arr)[rc] < (hp->arr)[index]) return;
			int num = (hp->arr)[lc] < (hp->arr)[rc] ? rc : lc;
			swap(&((hp->arr)[index]), &((hp->arr)[num]));
			index = num;
		}
	}
	return;
}

void insertAsLast(maxheap* hp, int data)
{
	if(hp->size) hp->arr = realloc(hp->arr, (hp->size + 1)*sizeof(int));
	else hp->arr = malloc(sizeof(int));
	hp->arr[hp->size] = data;
	(hp->size)++;

	//解决逆序
	percolateUp(hp, hp->size - 1); 
}

void delMax(maxheap* hp)
{
	(hp->arr)[0] = (hp->arr)[hp->size - 1];
	(hp->size)--;
	//解决逆序
	percolateDown(hp, 0);
}

int getMax(maxheap* hp)
{
	return (hp->arr)[0];
}

void buildHeap(maxheap* hp, int* arr, int size)
{
	hp->arr = malloc(sizeof(int)*(size + 1));
	for(int i = 0; i < size; i++)
	{
		(hp->arr)[i] = arr[i];
	}
	hp->size = size;

	//floyd algorithm, make it O(n)
	for(int j = (hp->size - 1) / 2; j >= 0; j--)
	{
		percolateDown(hp, j);
	}
}

int main()
{
	maxheap hp = init();
	int arr[] = {23,545,1,45465,145,65,24,5651,2456,4,32};
	int length = sizeof(arr) / sizeof(arr[0]);
	int count = 10;
	buildHeap(&hp, arr, length);
	while(count--)
	{
		if(count == 8)
		{
			insertAsLast(&hp, 1233321);	
		}
		int temp = getMax(&hp);
		printf("%d\n", temp);
		delMax(&hp);
	}
	return 0;
}

