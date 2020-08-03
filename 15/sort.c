#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **res;
    res = (int**)malloc(sizeof(int*)*numsSize*numsSize);
    if (res == NULL) {
        return NULL;
    }
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize*numsSize);
    if (res == NULL) {
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int i, target;
    *returnSize = 0;
    for (i = 0; i < numsSize*numsSize; i ++) {
        (*returnColumnSizes)[i] = 0;
    }
    for (i = 0; i < numsSize - 1; i ++) {
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        target = -nums[i];
        int left, right;
        left = i + 1;
        right = numsSize - 1;
        while (left < right) {
            //printf("%d %d %d\n", i, left, right);
            if (nums[left] + nums[right] == target) {
                int *ans;
                ans = (int*)malloc(sizeof(int) * 3);
                ans[0] = nums[i];
                ans[1] = nums[left];
                ans[2] = nums[right];
                res[*returnSize] = ans;
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize) ++;
                left ++;
                right --;
                while(nums[left] == nums[left-1] && left < right) left ++;
                while(nums[right] == nums[right+1] && left < right) right --;
                //printf("ans add : %d %d %d\n", ans[0], ans[1], ans[2]);
                continue;
            } else if (nums[left] + nums[right] < target) {
                left ++;
            } else if (nums[left] + nums[right] > target) {
                right --;
            }
        }
    }
    return res;
}

int main() {
    int a[6] = {-1, 0, 1, 0, 0, 0};
    int **res, *len, row;
    res = threeSum(a, 3, &row, &len);
    int i, j;
    for (i = 0; i < row; i ++) {
        for (j = 0; j < len[i]; j ++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}
