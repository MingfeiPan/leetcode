/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct ht_item {
    int key;
    int value;
} ht_item;

typedef struct hashtable {
    int size;
    ht_item** storage;
} hashtable;

hashtable* hash_create(int size);
void hash_destroy(hashtable* ht);
void hash_set(hashtable* ht, int key, int value);
ht_item* hash_get(hashtable* ht, int key);

hashtable* hash_create(int size){
    hashtable* ht = malloc(sizeof(hashtable));
    ht->size = size;
    ht->storage = calloc(size, sizeof(hashtable*));
    return ht;
}

void hash_destroy(hashtable* ht) {
    for(int i=0; i < ht->size; i++) {
		ht_item* item;
        if((item = ht->storage[i])) {
            free(item);
        }
    }
    free(ht->storage);
    free(ht);
}

void hash_set(hashtable* ht, int key, int value) {
	ht_item* item;
    item = (ht_item*)malloc(sizeof(ht_item));
    item->key = key;
    item->value = value;
    ht->storage[key] = item;
}

ht_item* hash_get(hashtable* ht, int key) {
	ht_item* item;
    if((item = ht->storage[key])) return item;
    return NULL;
}

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    hashtable* ht;
    ht_item* item;
    int* result = (int*)malloc(sizeof(int)*2);
    ht = hash_create(numsSize+1);
    for(int i = 0; i < numsSize; i++)
    {
        item = hash_get(ht, nums[i]);
        //注意hash的key 应该是数组的值
        
        if(!item) hash_set(ht, nums[i], 1);
        else
        {
            printf("%d\n", item->value);
            if(item->value == 1) hash_set(ht, nums[i], 2);
        }
    }
    for(int i = 1; i <= numsSize; i++)
    {
        item = hash_get(ht, i);
        if(!item) *(result+1) = i;
        else
        {
            if(item->value == 2) *result = i;
        }
    }
    *returnSize = 2;
    return result;
}
