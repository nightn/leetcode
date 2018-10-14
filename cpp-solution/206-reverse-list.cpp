#include <iostream>
#include <vector>
#include "999-utils.h"

using namespace std;

class Solution {
public:
    // 循环版本
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* r;
        head->next = NULL;  // important
        while (q) {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }

    // 递归版本
    ListNode* reverseList2(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* other = reverseList2(head->next);
        // 注意：此时 head->next 就是 other 的最后一个节点
        // 我之前错误地认为还需要再次遍历 other 才能求出 other 的最后一个节点
        head->next->next = head;
        head->next = NULL;
        return other;
    }

};

int main() {
    cout << "--- reverse list test ---" << endl;
    ListNode* list = constructList(vector<int>{1, 2, 3, 4, 5});
    printMyList(list);
    Solution sln;
    list = sln.reverseList2(list);
    printMyList(list);
}
