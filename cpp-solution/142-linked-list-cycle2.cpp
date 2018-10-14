#include <iostream>
#include <vector>
#include <map>
#include "999-utils.h"

using namespace std;

class Solution {
public:
    // 思路一：使用一个 map<ListNode*, int> 结构，遍历链表，统计每个节点出现的次数，
    // 如果遍历到 NULL，次数都为 1，那么没有环，
    // 如果某个节点次数为 2，那么该节点就是环的入口
    // 额外空间复杂度：O(N)
    // 时间复杂度：O(NlogN)，因为 map 的查找是 logN
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL) return NULL;
        map<ListNode*, int> cntMap;
        ListNode* cycleStart = NULL;
        ListNode* p = head;
        map<ListNode*, int>::iterator end = cntMap.end();
        while (p) {
            if (cntMap.find(p) == end) {
                cntMap[p] = 0;
            }
            ++cntMap[p];
            if (cntMap[p] == 2) return p;
            p = p->next;
        }
        return NULL;
    }

    // 思路二：两个指针 p, q，假如链表有环，环的大小为 m，
    // 一开始，p 指针头结点，q 指向第 m 个节点，然后 p, q 同时移动，
    // 它们相遇时的节点，就是环开始的节点。
    // 那如何确定换的大小呢？快慢指针相遇的节点一定在环上，然后该节点继续移动
    // 直至又回到该节点，那么移动的次数就是环的大小
    // 三趟遍历，时间复杂度 O(N)，空间复杂度 O(1)
    ListNode* detectCycle2(ListNode* head) {
        if (head == NULL || head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        if (fast->next == NULL || fast->next->next == NULL) return NULL;
        // 统计环的大小
        int m = 1;
        ListNode* p = slow->next;
        while (p != slow) {
            ++m;
            p = p->next;
        }
        cout << m << endl;
        // 两个指针
        ListNode* px = head;
        ListNode* py = head;
        int i = 0;
        while (i++ != m) {
            py = py->next;
        }
        while (px != py) {
            px = px->next;
            py = py->next;
        }
        return px;
    }


};

void cycle(ListNode* list) {
    Solution sln;
    ListNode* res = sln.detectCycle2(list);
    if (res) {
        cout << "Has cycle, cycle start: " << res->val << endl;
    } else {
        cout << "No cycle" << endl;
    }
}

int main() {
    Solution sln;
    ListNode* list1 = constructList(vector<int>{1, 2, 3, 4});
    ListNode* list2 = constructList(vector<int>{1, 2, 3, 4});
    // 1 -> 2 -> 3 -> 4( -> 2 )
    list2->next->next->next->next = list2->next;
    cycle(list1);
    cycle(list2);
}
