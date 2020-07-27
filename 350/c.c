#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 10000

struct hashnode {
    struct hashnode *next;
    int key;
    int cnt;
};

struct hash_head {
    struct hashnode *head;
};


struct hash_head *init() {
    struct hash_head *db;
    db = (struct hash_head*)malloc(sizeof(struct hash_head) * HASH_SIZE);
    int i;
    for (i = 0; i < HASH_SIZE; i ++) {
        db[i].head = NULL;
    }
    return db;
}

struct hashnode* new_node(int key) {
    struct hashnode *node;
    node = (struct hashnode*)malloc(sizeof(struct hashnode));
    if (node == NULL) {
        return NULL;
    }
    node->cnt = 1;
    node->next = NULL;
    node->key = key;
    return node;
}

int get_index(int key) {
    int real_key = key;
    while (real_key < 0) {
        real_key += HASH_SIZE;
    }
    return real_key % HASH_SIZE;
}

int hash_search_rec(struct hash_head *db, int key) {
    struct hashnode *p;
    int index = get_index(key);
    p = db[index].head;
    if (p == NULL) {
        return -1;
    }
    while(p != NULL) {
        if (p->key == key) {
            if (p->cnt > 0) {
                p->cnt --;
                return 0;
            }
        }
        p = p->next;
    }
    return -1;
}

int hash_insert(struct hash_head *db, int key) {
    int index = get_index(key);
    struct hashnode *p, *prev;
    p = db[index].head;
    if (p == NULL) {
        struct hashnode *node;
        node = new_node(key);
        if (node < 0) {
            return -1;
        }
        db[index].head = node;
        return 0;
    }
    while(p != NULL) {
        if (p->key == key) {
            p->cnt ++;
            return 0;
        }
        prev = p;
        p = p->next;
    }
    struct hashnode *node;
    node = new_node(key);
    if (node == NULL) {
        return -1;
    }
    prev->next = node;
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    struct hash_head *db;
    db = init();
    if (db == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int len = nums1Size;
    if (nums1Size > nums2Size) {
        len = nums2Size;
    }
    int *res;
    res = (int*)malloc(sizeof(int)*len);
    if (res == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int i, ret, cnt;
    for (i = 0; i < nums1Size; i ++) {
        ret = hash_insert(db, nums1[i]);
        if (ret < 0) {
            *returnSize = 0;
            return NULL;
        }
    }
    cnt = 0;
    for (i = 0; i < nums2Size; i ++) {
        ret = hash_search_rec(db, nums2[i]);
        if (ret == 0) {
            res[cnt ++] = nums2[i];
        }
    }
    *returnSize = cnt;
    return res;
}

int main() {
    int nums1[4] = {1, 2, 2, 1};
    int nums2[2] = {2, 2};
    int *res;
    int cnt;
    res = intersect(nums1, 4, nums2, 2, &cnt);
    printf("%d\n", cnt);
    int i;
    for (i = 0; i < cnt; i ++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}
