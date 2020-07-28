#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cmp(const void *a, const void *b) {
    return ( *(int *)a > *(int *)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int i, j;
    int len = nums1Size, cnt = 0;
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    i = 0;
    j = 0;
    if (nums1Size > nums2Size) {
        len = nums2Size;
    }
    int *res;
    res = (int*)malloc(sizeof(int)*len);
    if (res == NULL) {
        *returnSize = 0;
        return NULL;
    }
    while (i<nums1Size && j<nums2Size) {
        while (i < nums1Size && nums1[i] < nums2[j]) i ++;
        if (i >= nums1Size) break;
        while (j < nums2Size && nums2[j] < nums1[i]) j ++;
        if (j >= nums2Size) break;
        if (nums1[i] != nums2[j]) continue;
        //printf("%d %d %d %d\n", i, nums1[i], j, nums2[j]);
        res[cnt ++] = nums1[i];
        i ++;
        j ++;
    }
    *returnSize = cnt;
    return res;
}

int main() {
    int nums1[2] = {1, 2};
    int nums2[2] = {1, 1};
    int *res;
    int cnt;
    res = intersect(nums1, 2, nums2, 2, &cnt);
    printf("%d\n", cnt);
    int i;
    for (i = 0; i < cnt; i ++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}
