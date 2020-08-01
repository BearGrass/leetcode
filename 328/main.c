#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head){
    struct ListNode *p[2], *pos;
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        return head;
    }
    p[0] = head;
    p[1] = head->next;
    pos = p[1]->next;
    while(pos != NULL) {
        p[1]->next = pos->next;
        pos->next = p[0]->next;
        p[0]->next = pos;
        pos = p[1]->next;
        if(pos == NULL) {
            return head;
        }
        p[0] = p[0]->next;
        p[1] = p[1]->next;
        pos = pos->next;
    }
    return head;
}

int main() {
    struct ListNode *head;
    head = (struct ListNode*)malloc(sizeof(struct ListNode) * 10);
    int i;
    for (i = 0;i < 4; i ++) {
        head[i].val = i;
        head[i].next = head + i + 1;
    }
    head[3].next = NULL;
    struct ListNode *ans;
    ans = oddEvenList(head);
    struct ListNode *p = ans;
    while (p != NULL) {
        printf("%d\n", p->val);
        p = p->next;
    }
}
