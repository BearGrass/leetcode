#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int jump(int* nums, int numsSize) {
    int i;
    int longest = 0;
    int step = 0;
    int end = 0;
    if (numsSize == 1) {
        return 0;
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] + i >= longest) {
            longest = nums[i] + i;
            if (longest >= numsSize - 1) {
                return step + 1;
            }
        }
        if (i == end) {
            step ++;
            end = longest;
        }
    }
    return step;
}

int main() {
    int nums[] = {2,3,1,1,4};
    printf("%d\n", jump(nums, sizeof(nums) / sizeof(nums[0])));
}