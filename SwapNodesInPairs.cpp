#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x = 0) : val(x), next(NULL) {}
};
	
class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		ListNode *a = NULL;
		ListNode *b = NULL;
		ListNode *tail = NULL;
		ListNode *nhead = NULL;
		a = head;
		while (a != NULL && (b = a->next) != NULL) {
			a->next = b->next;
			b->next = a;
			if (tail != NULL) {
				tail->next = b;
			} else {
				nhead = b;
			}
			tail = a;
			a = a->next;
		}
		if (nhead == NULL) {
			nhead = head;
		}
		return nhead;
	}
};

void print (ListNode* head) {
	while (head != NULL) {
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}

int main() {
	ListNode arr[10];
	for (int i=0; i<10; i++) {
		arr[i].val = i + 1;
	}

	for (int i=0; i<0; i++) {
		arr[i].next = &arr[0] + i + 1;
	}
	print(&arr[0]);

	Solution s;
	ListNode* h = s.swapPairs(&arr[0]);
	print(h);

	return 0;
}
