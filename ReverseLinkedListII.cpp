#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL || n <= m) return head;
        int offset = n - m;

        ListNode* cur = head;
        ListNode* pre = NULL;

        while (cur != NULL && --m > 0) {
            pre = cur;
            cur = cur->next;
        }
        ListNode* start = cur;

        while (cur != NULL && offset-- > 0) {
            cur = cur->next;
        }
        ListNode* end = cur;
        ListNode* end_next = end->next;
        end->next = NULL;
        ListNode* rhead = reverse(start);

        if (pre == NULL) {
            head = rhead;
        } else {
            pre->next = rhead;
        }
        start->next = end_next;
        return head;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        while (cur != NULL) {
            ListNode* t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        return pre;
    }
};

void print(ListNode* list) {
    int i=0;
    while (list != NULL) {
        cout<<list->val<<" ";
        list = list->next;
        i++;
        if (i>10) break;
    }
    cout<<endl;
}

int main() {
    ListNode nodes[10];
    for (int i=0; i<10; i++) {
        nodes[i].val = i + 1;
        if (i < 9) {
            nodes[i].next = &nodes[i+1];
        }
    }
    nodes[2].next = NULL;
    
    ListNode* head = &nodes[0];
    print(head);
    
    Solution s;
    
    head = s.reverseBetween(head, 1, 2);
    
    print(head);
    
	system("pause");
	return 0;
}

