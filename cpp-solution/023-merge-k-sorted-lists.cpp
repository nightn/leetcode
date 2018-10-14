#include <iostream>
#include <vector>
#include "999-utils.h"

using namespace std;

class Solution {
public:
    // 思路一：调用合并两个链表的函数，每次加入一个链表进行合并
    // 确定：list 越来越大，越到后面，合并要遍历的节点也越多。可以改进
    // O(N^2)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        ListNode* list = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            list = mergeTwoLists(list, lists[i]);
        }
        return list;
    }

    // 思路二：使用归并排序的思想，分而治之
    // O(NlogN)
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        return doMergeKLists2(lists, 0, lists.size());
    }
    ListNode* doMergeKLists2(vector<ListNode*>& lists, int left, int right) {
        // 只有一个元素
        // 一开始把 left == right - 1 写成了 left = right - 1，调试了半天才发现
        if (left == right - 1) return lists[left];
        int mid = left + (right - left) / 2;
        ListNode* list1 = doMergeKLists2(lists, left, mid);
        ListNode* list2 = doMergeKLists2(lists, mid, right);
        return mergeTwoLists(list1, list2);
    }

    // help function
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        ListNode* p = list1;
        ListNode* q = list2;
        while (p && q) {
            if (p->val < q->val) {
                head->next = p;
                p = p->next;
            } else {
                head->next = q;
                q = q->next;
            }
            head = head->next;
        }
        while (p) {
            head->next = p;
            p = p->next;
            head = head->next;
        }
        while (q) {
            head->next = q;
            q = q->next;
            head = head->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main() {
    cout << "--- merge k sorted lists test ---" << endl;
    Solution sln;
    ListNode* list1 = constructList(vector<int>{1, 4, 5});
    ListNode* list2 = constructList(vector<int>{1, 3, 4});
    ListNode* list3 = constructList(vector<int>{2, 6});
    vector<ListNode*> lists;
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    printMyList(list1);
    printMyList(list2);
    printMyList(list3);

    ListNode* final = sln.mergeKLists2(lists);
    printMyList(final);

}
