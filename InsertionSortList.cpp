#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(NULL) {}
};

void print_list(ListNode* list, const char* msg);

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode* sorted_head = head;
        ListNode* unsorted_head = head->next;
        head->next = NULL;
        
        ListNode* cur = unsorted_head;

        while (cur != NULL) {
            unsorted_head = cur->next;
            cur->next = NULL;
            sorted_head = insertNode(sorted_head, cur);
            cur = unsorted_head;
        }
        
        return sorted_head;
    }
    
    ListNode* insertNode(ListNode* list, ListNode* node) {
        if (list == NULL && node == NULL) return NULL;
        if (node == NULL) return list;
        if (list == NULL) return node;
        ListNode* cur = list;
        ListNode* pre = NULL;
        while (cur != NULL && cur->val < node->val) {
            pre = cur;
            cur = cur->next;
        }
        if (pre == NULL) {
            node->next = list;
            return node;
        } else {
            node->next = pre->next;
            pre->next = node;
            return list;
        }
    }
};

void print_list(ListNode* list, const char* msg) {
    cout<<msg<<" ";
    ListNode* cur = list;
    while (cur != NULL) {
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
}

int main() {
    ListNode arr[10];
    for (int i=0; i < sizeof(arr) / sizeof(ListNode) - 1; i++) {
        arr[i].next = &arr[i+1];
    }
    
    arr[0].val = 3;
    arr[1].val = 2;
    arr[2].val = 4;
    arr[2].next = NULL;
    
    print_list(&arr[0], "before");
    Solution s;
    ListNode* ret = s.insertionSortList(&arr[0]);
    print_list(ret, "after");
	system("pause");
	return 0;
}

