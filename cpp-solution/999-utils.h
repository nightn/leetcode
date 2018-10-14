#ifndef __999_UTILS_H__
#define __999_UTILS_H__

#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

// 传入一个 vector<int>，构造一个 ListNode*
ListNode* constructList(const vector<int>& v) {
    if (!v.size()) return NULL;
    ListNode* result = new ListNode(v[0]);
    ListNode* r = result;
    for (int i = 1; i != v.size(); i++) {
        r->next = new ListNode(v[i]);
        r = r->next;
    }
    return result;
}


// all kinds of print
// print container
template <typename C>
void printContainer(const C& c) {
    for (auto it = c.begin(); it != c.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// print map
template <typename C>
void printMap(const C& c) {
    cout << "key    value" << endl; 
    for (auto it = c.begin(); it != c.end(); ++it) {
        cout << "  " << it->first << "    " << it->second << endl;
    }
}

void printMyList(ListNode* list) {
    if (list == NULL) {
        cout << "NULL" << endl;
        return;
    }
    ListNode* li = list;
    cout << li->val;
    while (li->next) {
        li = li->next;
        cout << " -> " << li->val;
    }
    cout << endl;
}


#endif
