#include <stdlib.h>
#include "999-utils.h";

// merge two sorted list
// 合并两个排好序的链表
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        // 哑结点，next 指针持有合并后的有序链表
        ListNode* header = new ListNode(0);
        ListNode* p = header;
        while (p1 != NULL && p2 != NULL) {
            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        while (p1 != NULL) {
            p->next = p1;
            p = p->next;
            p1 = p1->next;
        }
        while (p2 != NULL) {
            p->next = p2;
            p = p->next;
            p2 = p2->next;
        }
        // do not forget free memory
        ListNode* res = header->next;
        delete header;
        return res;
    }

    ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2)
    {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        // 哑结点，next 指针持有合并后的有序链表
        ListNode* header = new ListNode(0);
        ListNode* p = header;
        
        while (1) {
            if (!p1) {
                p->next = p2;
                break;
            } else if (!p2) {
                p->next = p1;
                break;
            }

            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }

        return header->next;
    }
};
