#include <iostream>
#include <vector>
#include "999-utils.h"

using namespace std;

// 删除链表倒数第 n 个节点
class Solution {
public:
    // 思路1：遍历一遍统计节点总个数 sum，倒数第 n 个节点即顺数第 sum - n + 1 个
    // 获取其前一个节点，即 sum - n，通过前一个节点来删除它
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sum = 0;
        // 习惯性用 p 坐标循环变量
        ListNode* p = head;
        while (p != NULL) {
            ++sum;
            p = p->next;
        }
        // index 为待删除节点的下标，从 0 开始
        int deleteIndex = sum - n;
        p = head;
        // 由于没有哑结点，当 deleteIndex == 0 时，需要单独考虑
        // 其实还可以手动添加哑结点
        if (deleteIndex != 0) {
            int i = deleteIndex;
            while (--i) {
                p = p->next;
            }
            // do delete
            // 不清楚传入的 list 是如何分配内存的，所以此处不手动释放内存
            p->next = p->next->next;
            return head;
        } else {
            ListNode* res = head->next;
            return res;
        }
    }

    // 和上一种解法一样，只是手动添加了哑结点来使边界情况一般化
    // 即不需要专门考虑删除首节点的情况了
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        int sum = 0;
        ListNode* p = head;
        while (p != NULL) {
            ++sum;
            p = p->next;
        }
        
        int deleteIndex = sum - n;
        // p 为待删除节点的前一个节点
        p = dummy;
        while (deleteIndex--) {
            p = p->next;
        }
        p->next = p->next->next;
        return dummy->next;
    }

    // 用快慢指针的思想，可以通过一次遍历来实现
    // 快指针先往前移动 n 步，然后快慢指针一起移动
    // 当快指针移动到尾部时，慢指针正好在期望位置
    ListNode* removeNthFromEnd3(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        int x = n;
        while (x--) {
            fast = fast->next;
        }

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        // 此时，slow 正指向待删除节点的前一个节点
        slow->next = slow->next->next;
        return dummy->next;
    }


};

// test
int main() {
    Solution s;

    vector<int> v = {1, 2, 3, 4, 5};
    ListNode* list = constructList(v);
    printMyList(list);

    list = s.removeNthFromEnd3(list, 5);
    printMyList(list);

}
