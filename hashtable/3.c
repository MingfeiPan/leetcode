/*
 * 同样借助hashtable, 但是set要修改 每次set遇到已经有值的key->value 时直接覆盖, 另外可以在测试时, 第一次遇到item为null时可以直接初始化value为-1
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

int max(int a, int b)
{
    return a < b ? b : a;
}

int lengthOfLongestSubstring(char* s) {
    hashtable* ht;
    ht_item* item;
    ht = hash_create(500);
    int maxnum = 0;
    int temp = -1;
    int length = strlen(s);
    for(int i = 0; i < length; i++)
    {
        item = hash_get(ht, s[i]);
        if(item == NULL)
        {
            hash_set(ht, s[i], -1);
        }
        item = hash_get(ht, s[i]);
        if(temp < item->value) temp = item->value;
        hash_set(ht, s[i], i);
        maxnum = max(maxnum, i - temp);
    }
    return maxnum;
}
