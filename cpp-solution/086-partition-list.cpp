#include <iostream>
#include <vector>
#include "999-utils.h"

using namespace std;

class Solution {
public:
    // 思路一：使用两个链表，遍历原始链表，小的放于 left，大的放于 right
    // 最后合并 left 和 right
    // 需要注意的是，要将 right 链表的最末尾元素的 next 置 NULL，不然可能产生环
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* leftDummy = new ListNode(0);
        ListNode* rightDummy = new ListNode(0);
        ListNode* p = head;
        ListNode* left = leftDummy;
        ListNode* right = rightDummy;
        while (p) {
            if (p->val < x) {
                left->next = p;
                left = left->next;
            } else {
                right->next = p;
                right = right->next;
            }
            p = p->next;
        }
        // connect
        right->next = NULL;  // important
        left->next = rightDummy->next;
        ListNode* result = leftDummy->next;
        return result;
    }
};


int main() {
    cout << "--- partition list test ---" << endl;
    ListNode* list = constructList(vector<int>{1, 4, 3, 2, 5, 2});;
    Solution sln;
    printMyList(list);
    list = sln.partition(list, 3);
    printMyList(list);

}
