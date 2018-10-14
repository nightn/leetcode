#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "999-utils.h"

using namespace std;

// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int x): val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a = l1;
        ListNode* b = l2;
        int sum = a->val + b->val;
        ListNode* result = new ListNode(sum % 10);
        ListNode* r = result;
        int carryBit = sum / 10;
        while (a->next && b->next) {
            a = a->next;
            b = b->next;
            sum = a->val + b->val + carryBit;
            r->next = new ListNode(sum % 10);
            r = r->next;
            carryBit = sum / 10;
        }
        while (a->next) {
            a = a->next;
            sum = a->val + carryBit;
            r->next = new ListNode(sum % 10);
            r = r->next;
            carryBit = sum / 10;
        }
        while (b->next) {
            b = b->next;
            sum = b->val + carryBit;
            r->next = new ListNode(sum % 10);
            r = r->next;
            carryBit = sum / 10;
        }
        // the last carryBit
        if (carryBit) {
            r->next = new ListNode(carryBit);
        }

        return result;
    }
};

int main() {
    Solution sln;
    
    ListNode* list1 = constructList(vector<int>{2, 4, 3});
    ListNode* list2 = constructList(vector<int>{5, 6, 4});

    ListNode* result = sln.addTwoNumbers(list1, list2);

    printMyList(list1);
    printMyList(list2);
    printMyList(result);

}
