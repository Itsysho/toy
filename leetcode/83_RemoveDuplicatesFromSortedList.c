// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL) return head;
    struct ListNode* pre = head;
    struct ListNode* cur = head->next;
    while (cur != NULL) {
        if (cur->val != pre->val) {
            pre->next = cur;
            pre = cur;
        } 
        cur = cur->next;
    }
    pre->next = NULL;
    return head;
}