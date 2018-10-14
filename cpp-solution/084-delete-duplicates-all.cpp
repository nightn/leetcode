#include <iostream>
#include <vector>
#include "999-utils.h"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        // 考虑两个节点的情况
        if (head->next->next == NULL) {
            if (head->val == head->next->val) return NULL;
            return head;
        }
        // 以下情况，节点个数至少为 3
        // 考虑到可能需要删除首节点，此处添加一个 dummy
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = head;
        ListNode* next = head->next;
        int repeat = -1000;
        while (cur && next) {
            if (cur->val == next->val) {
                // 删除重复的元素，并记录重复的数字
                next = next->next;
                cur->next = next;
                // 记录重复的数字
                repeat = cur->val;
            } else {
                if (cur->val == repeat) {
                    prev->next = next;
                    cur = next;
                    next = next->next;
                } else {
                    // 正常情况
                    prev = cur;
                    cur = next;
                    next = next->next;
                }
            }
        }
        if (cur->val == repeat) {
            prev->next = next;
        }

        head = dummy->next;
        // delete dummy;
        return head;
    }
};

int main() {
    Solution sln;
    // [1, 2, 3, 3, 4, 4, 5]
    ListNode* list = constructList(vector<int>{1, 2, 2});
    printMyList(list);
    list = sln.deleteDuplicates(list);
    printMyList(list);
}
