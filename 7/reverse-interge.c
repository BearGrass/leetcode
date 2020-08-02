#include <stdio.h>

int reverse(int x){
    int c = x;
    int ans = 0;
    while (c) {
        int v = c %10;
        if (x < 0) {
            if (ans < -214748364 || (ans == -214748364 && v < -8)) return 0;
            ans = ans * 10 + v;
        }
        if (x >= 0) {
            if (ans > 214748364 || (ans == 214748364 && v > 7)) return 0;
            ans = ans * 10 + v;
        }

    
        c = c / 10;
        //printf("%d %d %d\n", v, c, ans);
    }
    return ans;
}

int main() {
    int ans = reverse(1563847412);
    printf("%d\n", ans);
}
