#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x = 0) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {   
		ListNode* merged = NULL;
		for (int i=0; i<lists.size(); i++) {
			merged = merge_list(merged, lists[i]);
		}
		return merged;
	}

	// helper function to merge two sorted lists
	ListNode* merge_list(ListNode* l1, ListNode* l2) {
		ListNode* head = NULL;
		ListNode* tail = NULL;
		while (l1 != NULL && l2 != NULL) {
			ListNode* node = NULL;
			if (l1->val <= l2->val) {
				node = l1;
				l1 = l1->next;
			} else {
				node = l2;
				l2 = l2->next;
			}
			if (head == NULL) {
				head = node;
				tail = node;
			} else {
				tail->next = node;
				tail = node;
			}
		}
		if (l1 != NULL) {
			if (head == NULL) {
				head = l1;
			} else {
				tail->next = l1;
			}
		}
		if (l2 != NULL) {
			if (head == NULL) {
				head = l2;
			} else {
				tail->next = l2;
			}
		}
		return head;
	}
};

int main() {
	
	return 0;
}
