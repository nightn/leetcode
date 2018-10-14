#include <iostream>
#include <vector>
#include "999-utils.h"

using namespace std;

class Solution {
public:
    // 思路：先找到链表中点，将中点后面的节点逆序，然后使用两个指针 p, q
    // 分别指向 head 和末尾，同时往前遍历，直到其中一个指向 NULL
    // 空间复杂度 O(1)
    void reorderList(ListNode* head) {
        // 如果元素个数为 0, 1, 2，则直接 return
        if (head == NULL || head->next == NULL || head->next->next == NULL) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;
        ListNode* tail = reverseList(mid);
        // 两端往中间遍历
        // 如果不用额外空间，合并两个 list 很容易造成链表断开
        // 此处危机重重
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        ListNode* lastHead;
        while (head && tail) {
            p->next = head;
            head = head->next;
            p = p->next;

            p->next = tail;
            tail = tail->next;
            p = p->next;
        }
        p->next = NULL;  // 最后一定要置 NULL，不然链表无限循环
        delete dummy;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* r;
        head->next = NULL;
        while (q) {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }
};

int main() {
    Solution sln;
    ListNode* list = constructList(vector<int>{1, 2, 3, 4});
    printMyList(list);
    sln.reorderList(list);
    printMyList(list);
}
