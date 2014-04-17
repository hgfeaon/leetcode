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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *pre, *cur, *tmp;
        pre = head;
        cur = head->next;
        while (cur != NULL) {
            if (pre->val == cur->val) { // dup found
                tmp = cur;
                cur = tmp->next;
                pre->next = tmp->next;
                delete tmp;
            } else {
                pre = cur;
                cur = pre->next;
            }
        }
        return head;
    }
};

int main() {

	system("pause");
	return 0;
}

