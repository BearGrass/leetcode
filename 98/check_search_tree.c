#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int search(struct TreeNode* root, int *mi, int *ma) {
    int l, r;
    int is_leaf = 1;
    //printf("%d:\n", root->val);
    *mi = root->val;
    *ma = root->val;
    if (root->left != NULL) {
        int min, max;
        l = search(root->left, &min, &max);
        if (l == 0) {
            if (min >= root->val) return -1;
            if (*mi > min) *mi = min;
            if (max >= root->val) return -1;
            if (*ma < max) *ma = max;
        } else {
            return -1;
        }
        //printf("%d left: %d %d %d\n",root->val, l, *mi, *ma);
        is_leaf = 0;
    }
    if (root->right != NULL) {
        int min, max;
        r = search(root->right, &min, &max);
        if (r == 0) {
            if (min <= root->val) return -1;
            if (*mi > min) *mi = min;
            if (max <= root->val) return -1;
            if (*ma < max) *ma = max;
        } else {
            return -1;
        }
        //printf("%d right: %d %d %d\n",root->val, r, *mi, *ma);
        is_leaf = 0;
    }
    if (is_leaf) {
        *mi = root->val;
        *ma = root->val;
        return 0;
    }
    return 0;
}

bool isValidBST(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }
    int ret, min, max;
    ret = search(root, &min, &max);
    if (ret == 0) {
        return true;
    }
    return false;
}
