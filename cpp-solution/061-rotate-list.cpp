#include <iostream>
#include <vector>
#include "999-utils.h"

using namespace std;

class Solution {
public:
    // 思路：先求出链表的长度 len，k % len 即为要旋转的节点个数
    // x -> y -> newTail -> second -> z -> NULL
    // second -> z -> x -> y -> newTail -> NULL
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;
        
        // calcu len
        int len = 0;
        ListNode* p = head;
        ListNode* last;
        while (p != NULL) {
            if (p->next == NULL) last = p;
            ++len;
            p = p->next;
        }
        k = k % len;

        ListNode* newTail = head;
        ListNode* splitor = head->next;
        
        int i = len - k;
        while (--i) {
            newTail = newTail->next;
            splitor = splitor->next;
        }

        if (splitor == NULL) return head;

        ListNode* oldHead = head;
        head = splitor;
        last->next = oldHead;
        newTail->next = NULL;

        return head;
    }

    // no use
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* r;
        head->next = NULL;
        while (q != NULL) {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        head = q;
        return head;
    }

};

int main() {
    cout << "--- rotate list test ---" << endl;
    ListNode* list = constructList(vector<int>{1, 2, 3, 4, 5});
    Solution sln;
    int k = 2;
    printMyList(list);
    list = sln.rotateRight(list, 2);
    printMyList(list);
}
