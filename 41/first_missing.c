inline int abs(int x) {
    return x<0?-x:x;
}
int firstMissingPositive(int* nums, int numsSize){
    int i;
    for (i = 0; i < numsSize; i ++) {
        if (nums[i] <= 0) nums[i] = numsSize + 1;
    }
    for (i = 0; i < numsSize; i ++) {
        if (abs(nums[i]) <= numsSize) {
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        }
    }
    for (i = 0; i < numsSize; i ++) {
        if (nums[i] > 0) return i + 1;
    }
    if (numsSize == 0) return 1;
    return numsSize + 1;
}


