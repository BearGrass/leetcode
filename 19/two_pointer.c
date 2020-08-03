#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *cur, *prev;
    int cnt;
    cnt = 0;
    cur = head;
    prev = cur;
    if (n == 0) {
        return head;
    }
    while (cur && cnt < n) {
        cur = cur->next;
        cnt ++;
    }
    if (cur == NULL) {
        if (cnt == n) {
            return head->next;
        }
        return NULL;
    }
    while(cur->next != NULL) {
        cur = cur->next;
        prev = prev->next;
    }
    if (n == 1) {
        prev->next = NULL;
    } else {
        prev->next = prev->next->next;
    }
    return head;
}

int main() {
    struct ListNode *list;
    list = (struct ListNode*)malloc(sizeof(struct ListNode) * 20);
    int i;
    for (i = 0; i < 5; i ++) {
        list[i].val = i+1;
        list[i].next = &list[i+1];
    }
    list[4].next = NULL;
    struct ListNode *ans;
    ans = removeNthFromEnd(list, 5);
    while (ans) {
        printf("%d\n", ans->val);
        ans = ans->next;
    }
}
