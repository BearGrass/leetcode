#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(int* nums, int numsSize, int k){
    int i, j, pos, d;
    int temp, cnt;
    cnt = 0;
    k %= numsSize;
    for (i = 0; i < k; i ++) {
        temp = nums[i];
        pos = i;
        j = (pos + numsSize - k) % numsSize;
        while (j != i) {
            //printf("%d %d %d %d\n", pos, nums[pos], j, nums[j]);
            nums[pos] = nums[j];
            pos = j;
            j = (pos + numsSize - k) % numsSize;
            cnt ++;
        }
        nums[pos] = temp;
        cnt ++;
        /*
        for (d = 0; d < numsSize; d ++) {
            printf("%d ", nums[d]);
        }
        printf("\n");
        */
        if (cnt == numsSize) break;
    }
}

int main() {
}
