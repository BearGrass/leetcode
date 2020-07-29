#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 1000

typedef struct hash_node {
    int key;
    int value;
    struct hash_node *next, *tail;
} hash_node_t;

typedef struct {
    int key, value;
} heap_node_t;

int hash_insert(hash_node_t **db, hash_node_t *list, int key, int hash_size) {
    int index = key;
    hash_node_t *cur, *p;
    if (index < 0) index = -index;
    index %= hash_size;
    cur = db[index];
    p = cur->next;
    while (p) {
        if (p->key == key) {
            p->value ++;
            return 0;
        }
        p = p->next;
    }
    hash_node_t *new_node;
    new_node = (hash_node_t*)malloc(sizeof(hash_node_t));
    if (new_node == NULL) {
        return -1;
    }
    new_node->key = key;
    new_node->value = 1;
    new_node->next = cur->next;
    cur->next = new_node;
    new_node->tail = list->tail;
    list->tail = new_node;
    return 0;
}

void heap_insert(heap_node_t *hp, int size, int key, int value) {
    int i, prev;
    ++ size;
    hp[size].key = key;
    hp[size].value = value;
    for (i = size; i > 1; i = i / 2) {
        prev = i / 2;
        if (hp[prev].value > value) {
            hp[i].key = hp[prev].key;
            hp[i].value = hp[prev].value;
        } else {
            break;
        }
    }
    hp[i].key = key;
    hp[i].value = value;
}

void heap_pop(heap_node_t *hp, int size) {
    int key, value;
    key = hp[size].key;
    value = hp[size].value;
    size --;
    hp[1].key = key;
    hp[1].value = value;
    int i, next;
    for (i = 1; 2 * i <= size; i = next) {
        next = i * 2;
        if (next + 1 <= size && hp[next].value >= hp[next + 1].value) next ++;
        if (value > hp[next].value) {
            hp[i].key = hp[next].key;
            hp[i].value = hp[next].value;
        } else {
            break;
        }
    }
    hp[i].key = key;
    hp[i].value = value;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    int *res;
    int i, ret, heap_size;
    *returnSize = k;
    res = (int*)malloc(sizeof(int) * k);
    if (res == NULL) {
        *returnSize = 0;
        return NULL;
    }
    hash_node_t **db;
    db = (hash_node_t**)malloc(sizeof(hash_node_t*) * HASH_SIZE);
    if (db == NULL) {
        *returnSize = 0;
        return NULL;
    }
    for (i = 0; i < HASH_SIZE; i ++) {
        db[i] = (hash_node_t*)malloc(sizeof(hash_node_t));
        db[i]->key = 0;
        db[i]->value = 0;
        db[i]->next = NULL;
        db[i]->tail = NULL;
    }
    hash_node_t *list_head;
    list_head = (hash_node_t*)malloc(sizeof(hash_node_t));
    for (i = 0; i < numsSize; i ++) {
        ret = hash_insert(db, list_head, nums[i], HASH_SIZE);
        if (ret < 0) {
            *returnSize = 0;
            return NULL;
        }
    }
    hash_node_t *p = list_head->tail;
    heap_size = 0;
    heap_node_t *hp = (heap_node_t*)malloc(sizeof(heap_node_t) * k + 1);
    if (hp == NULL) {
        *returnSize = 0;
        return NULL;
    }
    while (p != NULL) {
        if (heap_size < k) {
            heap_insert(hp, heap_size, p->key, p->value);
            heap_size ++;
        } else {
            if (hp[1].value < p->value) {
                heap_pop(hp, heap_size);
                heap_size --;
                heap_insert(hp, heap_size, p->key, p->value);
                heap_size ++;
            }
        }
        p = p->tail;
    }
    for (i = 0; i < k; i ++) {
        res[i] = hp[i+1].key;
    }
    *returnSize = k;
    return res;
}
int main() {
    int arr[4] = {3, 0, 1, 0};
    int k = 1;
    int *res;
    int res_len;
    res = topKFrequent(arr, 4, k, &res_len);
    int i;
    for (i = 0; i < res_len; i ++) {
        printf("%d ", res[i]);
    }
    printf("\n");
}

