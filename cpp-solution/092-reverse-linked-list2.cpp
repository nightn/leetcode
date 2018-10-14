#include <iostream>
#include <vector>
#include "999-utils.h"

using namespace std;

// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL

class Solution {
public:
    // 思路：首先，遍历链表，找到 m 和 n 位置的节点，
    // 将 n 节点的下一个节点暂存，并 n->next = NULL
    // 逆序 m 链表。最后拼接
    // 该算法两趟遍历，时间复杂度为 O(N)
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* p = head;
        ListNode* left;
        ListNode* right;
        // firstEnd 指第一段的末尾节点
        // thirdStart 指第三段的首节点
        // 它们是用来和中间逆序的第二段进行拼接的
        ListNode* firstEnd = NULL;
        int i = 0;
        while (p) {
            ++i;
            if (i == m - 1) firstEnd = p;
            if (i == m) left = p;
            if (i == n) {
                right = p;
                break;
            }
            p = p->next;
        }
        ListNode* thirdStart = right->next;
        right->next = NULL;
        left = reverseList(left);
        if (firstEnd) {
            firstEnd->next->next = thirdStart;
            firstEnd->next = left;
        } else {
            head->next = thirdStart;
            head = left;
        }
        return head;
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
    ListNode* list = constructList(vector<int>{1, 2, 3, 4, 5});
    printMyList(list);
    int m = 3;
    int n = 4;
    list = sln.reverseBetween(list, m, n);
    printMyList(list);
}
