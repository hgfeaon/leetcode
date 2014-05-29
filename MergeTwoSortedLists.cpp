#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x = 0) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode* p = l1;
		ListNode* q = l2;
		ListNode* head = NULL;
		ListNode* tail = NULL;
		ListNode* node = NULL;
		
		while (p != NULL && q != NULL) {
			if (p->val <= q->val) {
				node = p;
				p = p->next;
			} else {
				node = q;
				q = q->next;
			}
			add_node(head, tail, node);		
		}
		while (p != NULL) {
			add_node(head, tail, p);
			p = p->next;
		}
		while (q != NULL) {
			add_node(head, tail, q);
			q = q->next;
		}
		return head;
	}

	void add_node(ListNode* &head, ListNode* &tail, ListNode* node) {
		if (head == NULL) {
			head = node;
			tail = node;
		} else {
			tail->next = node;
			tail = node;
		}
	}
};

int main() {
	Solution s;
	return 0;
}
