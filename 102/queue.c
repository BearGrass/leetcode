#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct queue {
    struct queue *next;
    struct TreeNode *node;
    int step;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    struct queue *head, *tail, *first;
    int step, cnt, len, total;
    head = (struct queue*)malloc(sizeof(struct queue));
    tail = (struct queue*)malloc(sizeof(struct queue));
    head->next = tail;
    tail->node = root;
    tail->next = NULL;
    tail->step = 1;
    first = tail;
    step = 1;
    cnt = 1;
    len = 1;
    total = 0;
    *returnSize = 1;
    while (head != tail) {
        head = head->next;
        total ++;
        if (head->step != step) {
            cnt = 0;
            step = head->step;
        }
        if (head->node->left != NULL) {
            tail->next = (struct queue*)malloc(sizeof(struct queue));
            tail = tail->next;
            tail->node = head->node->left;
            tail->step = head->step + 1;
            if (*returnSize < tail->step) {
                *returnSize = tail->step;
            }
            cnt ++;
            tail->next = NULL;
        }
        if (head->node->right != NULL) {
            tail->next = (struct queue*)malloc(sizeof(struct queue));
            tail = tail->next;
            tail->node = head->node->right;
            tail->step = head->step + 1;
            tail->next = NULL;
            if (*returnSize < tail->step) {
                *returnSize = tail->step;
            }
            cnt ++;
            tail->next = NULL;
        }
    }
    //printf("%d %d\n", *returnSize, total);
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    int **res, i;
    res = (int**)malloc(sizeof(int*) * (*returnSize));
    for (i = 0; i < (*returnSize); i ++) {
        res[i] = (int*)malloc(sizeof(int) * (total/2+1));
        (*returnColumnSizes)[i] = 0;
    }
    while(first) {
        int level = first->step - 1;
        //printf("%d %d %d\n", level, first->node->val, (*returnColumnSizes)[level]);
        res[level][(*returnColumnSizes)[level]] = first->node->val;
        (*returnColumnSizes)[level] ++;
        first = first->next;
    }
    return res;
}
int main() {
    return 0;
}
