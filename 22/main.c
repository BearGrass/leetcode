#include "stdlib.h"
#include "stdio.h"
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **generateParenthesis(int n, int *returnSize)
{
    int i, ck, state, rcnt = 0;
    int max = (1 << (2 * n)) - 1;
    // printf("max = %d\n", max);
    char **res = malloc(sizeof(char *) * max);
    for (state = 0; state <= max; state++)
    {
        // printf("state = %d\n", state);
        int temp[17];
        for (int i = 0; i < 2*n; i++)
        {
            temp[i] = 0;
        }
        for (int i = 0; i < 2*n; i++)
        {
            if (state & (1 << i))
            {
                temp[i] = 1;
            }
        }
        // check temp is ok
        int stack = 0;
        for (int i = 0; i < 2*n; i++)
        {
            if (temp[i] == 0)
            {
                stack++;
            }
            else
            {
                stack--;
            }
            if (stack < 0)
            {
                break;
            }
        }
        if (stack == 0)
        {
            char *temp_res = malloc(sizeof(char) * (2 * n + 1));
            for (int i = 0; i <2*n; i++)
            {
                if (temp[i] == 0)
                {
                    temp_res[i] = '(';
                }
                else
                {
                    temp_res[i] = ')';
                }
            }
            temp_res[2*n] = '\0';
            // printf("%s\n", temp_res);
            res[rcnt] = temp_res;
            rcnt++;
            // printf("returnSize = %s %d\n", temp_res, *returnSize);
        }
    }
    *returnSize = rcnt;
    return res;
}

int main()
{
    int n = 1;
    int returnSize = 0;
    char **res;
    res = generateParenthesis(n, &returnSize);
    int i;
    // printf("returnSize = %d\n", returnSize);
    for (i = 0; i < returnSize; i ++) {
        printf("res = %s\n", res[i]);
        // free(res[i]);
    }
    // free(res);
}
