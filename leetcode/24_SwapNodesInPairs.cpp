// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// sol 1
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* ret = head->next;

        ListNode* pre = NULL;
        ListNode* cur = head;
        while (cur != NULL) {
            ListNode *p = cur;
            ListNode *q = cur->next;

            if (q == NULL) {
                if (pre != NULL)
                    pre->next = p;
                break;
            }

            cur = q->next;
            if (pre != NULL)
                pre->next = q;
            q->next = p;
            pre = p;
            p->next = NULL;
        }

        return ret;
    }
};

// sol 2
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* ret = head->next;
        head->next = swapPairs(ret->next);
        ret->next = head;

        return ret;
    }
};