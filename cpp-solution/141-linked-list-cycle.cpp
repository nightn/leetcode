#include <iostream>
#include <vector>
#include "999-utils.h"

using namespace std;

class Solution {
public:
    // 检测一个单链表是否有环，最简单的方法是使用快慢指针
    // 慢指针一次走一步，快指针一次走两步，当最后发现快指针等于慢指针时，说明有环
    bool hasCycle(ListNode *head) {
        // 如果链表没有节点或只有一个节点，是不能构成环的
        if (head == NULL || head->next == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;

    }
};

int main() {
    ListNode* list = constructList(vector<int>{1, 2});
    list->next->next = list;
    Solution sln;
    cout << sln.hasCycle(list) << endl;
}
