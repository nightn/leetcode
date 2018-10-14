#include <iostream>
#include <vector>
#include "999-utils.h"

using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* r;
        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;
        while (p != NULL && q != NULL) {
            r = q->next;
            q->next = NULL;  // 这句话一开始写成 q = NULL，害我调试半天
            p = reverseList(p);
            temp->next = p;
            temp = p->next;
            p = r;
            if (p == NULL) return newHead->next;
            q = p->next;
        }
        temp->next = p;
        return newHead->next;
    }

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
        head = p;
        return head;
    }

    // TODO 递归版本

};

int main() {
    cout << "--- swap pair test---" << endl;
    ListNode* list = constructList(vector<int>{1, 2, 3, 4, 5});
    printMyList(list);
    Solution sln;
    list = sln.swapPairs(list);
    printMyList(list);
}
