#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x = 0) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode* p = l1;
		ListNode* q = l2;
		ListNode* ret = NULL;
		ListNode* ret_cur = NULL;
		int carry = 0;
		int digit = 0;
		while (p != NULL && q != NULL) {
			carry = add_node(p->val + q->val + carry, ret, ret_cur); 
			p = p->next;
			q = q->next;
		}
		while (p != NULL) {
			carry = add_node(p->val + carry, ret, ret_cur); 
			p = p->next;
		}
		while (q != NULL) {
			carry = add_node(q->val + carry, ret, ret_cur); 
			q = q->next;
		}
		if (carry) add_node(1, ret, ret_cur);
		return ret;
	}

	int add_node(int val, ListNode* &head, ListNode* &cur) {
		int carry = val / 10;
		int digit = carry == 0 ? val : val - 10;
		ListNode* cur_res = new ListNode(digit);
		if (head == NULL) {
			head = cur_res;
			cur = cur_res;
		} else {
			cur->next = cur_res;
			cur = cur_res;
		}
		return carry;
	}
};

void print(ListNode* list) {
	while (list != NULL) {
		cout<<list->val<<" ";
		list = list->next;
	}
	cout<<endl;
}

int main() {
	ListNode n[10];
	n[0].val = 8;
	n[1].val = 7;
	n[2].val = 6;
	n[3].val = 5;
	n[0].next = &n[1];
	n[2].next = &n[3];

	cout<<"Number 1:";
	print(&n[0]);
	cout<<"Number 2:";
	print(&n[2]);

	Solution s;
	ListNode* res = s.addTwoNumbers(&n[0], &n[2]);
	cout<<"res:";
	print(res);
	return 0;
}
