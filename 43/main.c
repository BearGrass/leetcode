#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    int len1, len2;
    len1 = strlen(num1);
    len2 = strlen(num2);
    int temp[len1 + len2];
    memset(temp, 0, sizeof(temp));
    int i, j, pos1, pos2;
    for (i = len1 - 1; i >= 0; i --) {
        // printf("%c %s\n", num1[i], num2);
        for (j = len2 - 1; j >= 0; j --) {
            pos1 = len1 - 1 - i;
            pos2 = len2 - 1 - j;
            temp[pos1 + pos2] += (num1[i] - '0') * (num2[j] - '0');
            temp[pos1 + pos2+ 1] += temp[pos1 + pos2] / 10;
            temp[pos1 + pos2] %= 10;
            // printf("%d %d %d\n", pos1, pos2, temp[pos1 + pos2]);
        }
        // for (j = pos1 + pos2 + 1; j >= 0; j --) {
        //     printf("%d", temp[j]);
        // }
        // printf("\n");
    }
    char* res = (char*)malloc(len1 + len2 + 1);
    memset(res, '0', len1 + len2 + 1);
    int pos = 0;
    for (i = len1 + len2 - 1; i >= 0; i --) {
        res[pos] = temp[i] + '0';
        pos ++;
    }
    int start = 0;
    while (res[start] == '0') {
        start ++;
    }
    return res + start;
}

int main() {
    char* num1 = "2";
    char* num2 = "3";
    printf("%s", multiply(num1, num2));
    return 0;
}