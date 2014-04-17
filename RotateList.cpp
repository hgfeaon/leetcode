#include <iostream>
#include <cstdlib>

using namespace std;
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return NULL;
        ListNode *p = head, *q = head;
        L
        int dst = k;
        while (dst--) {
            q = q->next;
            if (q == NULL) {
                q = head;
                k = k % (k - dst);
                dst = k;
            }
        }
        if (p == q) return head;
        while (q->next != NULL) {
            q = q->next;
            p = p->next;
        }
        ListNode *new_head = p->next;
        p->next = NULL;
        q->next = head;
        return new_head;
    }
};


int main() {
    Solution s;
    
    
	system("pause");
	return 0;
}

