#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *ans = l1;
    struct ListNode *cur, *next;
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    if (l1->val > l2->val) {
        cur = l1;
        l1 = l2;
        l2 = cur;
        ans = l1;
    }
    cur = l1;
    next = l1->next;
    while (l2 && next) {
        if (l2->val > next->val) {
            cur = next;
            next = cur->next;
            continue;
        }
        cur->next = l2;
        l2 = l2->next;
        cur->next->next = next;
        cur = cur->next;
    }
    if (next == NULL) {
        while(l2) {
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }
    }
    return ans;
}

int main() {
    struct ListNode *l1, *l2;
    l1 = (struct ListNode*)malloc(sizeof(struct ListNode) * 100);
    l2 = (struct ListNode*)malloc(sizeof(struct ListNode) * 100);
    int i;
    l1[0].val = 2;
    l1[1].val = 2;
    l1[2].val = 4;
    for (i = 0; i < 3; i ++) {
        l1[i].next = &l1[i+1];
    }
    l1[2].next = NULL;

    l2[0].val = 5;
    l2[1].val = 6;
    l2[2].val = 7;
    for (i = 0; i < 3; i ++) {
        l2[i].next = &l2[i+1];
    }
    l2[2].next = NULL;
    struct ListNode *ans, *p;
    ans = mergeTwoLists(l1, l2);
    p = ans;
    while(p) {
        printf("%d ", p->val);
        p = p->next;
    }
}
