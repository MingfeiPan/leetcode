/**
 * naive solution, o(n2) and pretty slow
 * [twoSum description]
 * @param  nums     [description]
 * @param  numsSize [description]
 * @param  target   [description]
 * @return          [description]
 */
// int* twoSum(int* nums, int numsSize, int target) {
// 	int *ret = malloc(sizeof(int)*2);
// 	for (int i = 0; i < numsSize; ++i)
// 	{
// 		// if (numsSize-1 > i && nums[i] > target) continue;
// 	 	for (int j = 0; i < numsSize; ++j)
// 	 	{
// 	 		if ((j != i) && (nums[i] + nums[j] == target)) 
// 	 		{
// 	 			ret[0] = i;
// 	 			ret[1] = j;
// 	 			return ret;
// 	 		}
// 	 	}
// 	} 
// 	return 0;
// }

/**
 * better one
 * use hashmap
 */
#include <stdio.h>
#include <stdlib.h> 

typedef struct HashNode
{
	int key;
	int val;
}HashNode;

typedef struct HashMap {
    int size;
    HashNode** storage;
} HashMap;

HashMap* create(int size);
void destory(HashMap* hashMap);
void set(HashMap* hashMap, int key, int value);
HashNode* get(HashMap* hashMap, int key);

HashMap* create(int size)
{
	HashMap* hp = malloc(sizeof(HashMap));
	hp->size = size;
	hp->storage = calloc(size, sizeof(HashNode));
	return hp;
}

void destory(HashMap* hp)
{
	for (int i = 0; i < hp->size ; ++i)
	{
		HashNode* node;
		if ((node = hp->storage[i]))
		{
			free(node);
		}
	}
	free(hp->storage);
	free(hp);
}

void set(HashMap* hp, int key, int value)
{
	int hash = abs(key) % hp->size;
	HashNode* node;
	while((node = hp->storage[hash]))
	{
		if (hash < (hp->size-1))
		{
			hash++;
		}
		else
		{
			hash = 0;
		}
	}
	node = malloc(sizeof(HashNode));
	node->key = key;
	node->val = value;
	hp->storage[hash] = node;
}

HashNode* get(HashMap* hp, int key)
{
	int hash = abs(key) % hp->size;
	HashNode* node;
	while((node = hp->storage[hash]))
	{
		if (node->key == key)
		{
			return node;
		}

		if (hash < (hp->size - 1))
		{
			hash++;
		}
		else
		{
			hash = 0;
		}
	}
	return NULL;
}


int* twoSum(int* nums, int numsSize, int target) 
{
	HashMap* hp;
	HashNode* node;
	int rest, i;
	int* result = malloc(sizeof(int)*2);
	// int* result;
	hp = create(numsSize*2); //for collision occurs extra space
	for (int i = 0; i < numsSize; ++i)
	{
		rest = target - nums[i];
		node = get(hp, rest);
		if (node)
		{
			result[0] = node->val + 1;
			result[1] = i + 1;
			destory(hp);
			return result;	
		}
		else
		{
			set(hp, nums[i], i);
		}
	}
	// result[0] = 1;
	// result[1] = 2;
 //    return result;	

}


