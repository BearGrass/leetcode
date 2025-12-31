#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    struct ListNode *p = head;
    struct ListNode *next = p->next;
    while (p != NULL && next != NULL) {
        int temp = p->val;
        p->val = next->val;
        next->val = temp;
        p = next->next;
        if (p != NULL) next = p->next;
    }
    return head;
}

int main() {
    struct ListNode* ln;
}