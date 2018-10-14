#include <iostream>
#include <vector>
#include "999-utils.h"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* p = head;
        while (p && p->next) {
            if (p->val == p->next->val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        // 此处一开始忘记 return 了，何时才能写出不需要编译器提示的 bug free code
        return head;
    }
};


int main() {
    cout << "--- delete duplicates test ---" << endl;
    Solution sln;
    ListNode* list = constructList(vector<int>{1, 1, 2, 3, 3});
    printMyList(list);
    list = sln.deleteDuplicates(list);
    printMyList(list);
}
