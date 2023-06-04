// Given the head of a singly linked list, reverse the list, and return the reversed list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL) return head;
    struct ListNode* prev = head;
    struct ListNode* cur = prev->next;
    head->next =  NULL;
    while (prev != NULL && cur != NULL) {
        struct ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}