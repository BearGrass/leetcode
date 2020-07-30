#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfs(struct TreeNode* cur, int *global_sum) {
    int lsum = 0, rsum = 0;
    int is_leaf = 1;
    if (cur->left != NULL) {
        is_leaf = 0;
        lsum = dfs(cur->left, global_sum);
        if (*global_sum < lsum) {
            *global_sum = lsum;
        }
    }
    if (cur->right != NULL) {
        is_leaf = 0;
        rsum = dfs(cur->right, global_sum);
        if (*global_sum < rsum) {
            *global_sum = rsum;
        }
    }
    if (is_leaf) {
        if (cur->val > *global_sum) {
            *global_sum = cur->val;
        }
        return cur->val;
    }
    if (*global_sum < cur->val + lsum + rsum) {
        *global_sum = cur->val + lsum + rsum;
    }
    printf("%d %d (%d %d)\n", cur->val, *global_sum, lsum, rsum);
    int sum;
    if (lsum > rsum) {
        sum = lsum + cur->val;
    } else {
        sum = rsum + cur->val;
    }
    if (cur->val < 0) {
        if (sum > cur->val) {
            return sum;
        } else {
            return cur->val;
        }
    } else if (cur->val >= 0) {
        if (sum > cur->val) {
            if (sum  > *global_sum) {
                *global_sum = sum;
            }
            return sum;
        } else {
            if (cur->val > *global_sum) {
                *global_sum = cur->val;
            }
            return cur->val;
        }
    }
    return 0;
}

int maxPathSum(struct TreeNode* root){
    int sum = -9999999;
    int ret;
    ret = dfs(root, &sum);
    if (ret > sum) sum = ret;
    return sum;
}

int main() {
    struct TreeNode *root, *tree;
    tree = (struct TreeNode*)malloc(sizeof(struct TreeNode) * 16);
    root = tree;
    int arr[7] = {-10, 9, 20, 0, 0, 15, 7};
    int i;
    for (i = 0; i < 7; i ++) {
        tree[i].left = NULL;
        tree[i].right = NULL;
    }
    for (i = 0; i < 7; i ++) {
        tree[i].val = arr[i];
        int left, right;
        left = i * 2 + 1;
        right = i * 2 + 2;
        if (left < 7) {
            if (arr[left] != 0) {
                tree[i].left = &tree[left];
            }
        }
        if (right < 7) {
            if (arr[right] != 0) {
                tree[i].right = &tree[right];
            }
        }
    }
    int res;
    res = maxPathSum(root);
    printf("%d\n", res);
    return 0;
}
