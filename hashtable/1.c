/**
 * 借助hashtable, 把要求的值做key 来提升效率
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
    int hash = abs(key) % ht->size;
	ht_item* item;
    while ((item = ht->storage[hash])) {
        if (hash < ht->size - 1) {
            hash++;
        } else {
            hash = 0;
        }
    }
    item = malloc(sizeof(hashtable));
    item->key = key;
    item->value = value;
    ht->storage[hash] = item;
}

ht_item* hash_get(hashtable* ht, int key) {
    int hash = abs(key) % ht->size;
	ht_item* item;
    while ((item = ht->storage[hash])) {
        if (item->key == key) {
            return item;
        }

        if (hash < ht->size - 1) {
            hash++;
        } else {
            hash = 0;
        }
    }

    return NULL;
}

int* twoSum(int* nums, int numsSize, int target) {
    hashtable* ht;
    ht_item* item;
    int temp;
    int* result = malloc(sizeof(int)*2);
    ht = hash_create(numsSize*2);
    for(int i = 0; i<numsSize; i++)
    {
        temp = target - nums[i];
        item = hash_get(ht, temp);
        if(item)
        {
            result[0] = item->value;
            result[1] = i;
            hash_destroy(ht);
            return result;
        }
        else
        {
            hash_set(ht, nums[i], i);
        }
    }
    return result;
}
