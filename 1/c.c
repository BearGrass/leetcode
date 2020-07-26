#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 10000

struct hash_node {
    int index;
    int value;
    struct hash_node *next;
    struct hash_node *prev;
};

struct hash_head {
    struct hash_node *head;
    struct hash_node *tail;
};

struct hash_head *db;

struct hash_head *hash_init() {
    struct hash_head *db;
    db = (struct hash_head*)malloc(sizeof(struct hash_head) * HASH_SIZE);
    if (db == NULL) {
        return NULL;
    }
    int i;
    for (i = 0; i < HASH_SIZE; i ++) {
        db[i].head = NULL;
        db[i].tail = NULL;
    }
    return db;
}

struct hash_node *search_node(struct hash_head *db, int num) {
    struct hash_node *head;
    if (num < 0) {
        head = db[(num + HASH_SIZE)].head;
    } else {
        head = db[num%HASH_SIZE].head;
    }
    while (head != NULL) {
        if (head->value == num) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

struct hash_node *insert_node(struct hash_head *db, int num, int index) {
    struct hash_head *bucket;
    struct hash_node *head, *prev;
    if (num < 0) {
        bucket = &db[(num + HASH_SIZE)];
    } else {
        bucket = &db[num%HASH_SIZE];
    }
    head = bucket->head;
    prev = NULL;
    while (head != NULL) {
        if (head->value == num) {
            return head;
        }
        prev = head;
        head = head->next;
    }
    struct hash_node *new_node;
    new_node = (struct hash_node*)malloc(sizeof(struct hash_node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->value = num;
    new_node->index = index;
    new_node->next = NULL;
    if (prev == NULL) {
        bucket->head = new_node;
        new_node->prev = new_node;
    } else {
        new_node->prev = prev;
        prev->next = new_node;
    }
    bucket->tail = new_node;
    return new_node;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    db = hash_init();
    if (db == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int *res;
    res = (int*)malloc(sizeof(int) * 2);
    if (res == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int i;
    struct hash_node *node;
    for (i = 0; i < numsSize; i ++) {
        node = search_node(db, target - nums[i]);
        if (node != NULL) {
            res[0] = node->index;
            res[1] = i;
            *returnSize = 2;
            return res;
        }
        node = insert_node(db, nums[i], i);
        if (node == NULL) {
            *returnSize = 0;
            return NULL;
        }
    }
    *returnSize = 0;
    return NULL;
}

int main() {
    int arr[4] = {1, 2, 3, 4};
    int numsSize = 4;
    int target = 6;
    int ret;
    int *res;
    res = twoSum(arr, numsSize, target, &ret);
    int i;
    for (i = 0; i < ret; i ++) {
        printf("%d ", res[i]);
    }
    printf("\n");
}
