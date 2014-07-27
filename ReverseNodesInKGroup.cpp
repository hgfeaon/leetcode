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
    ListNode *reverseKGroup(ListNode *head, int k) {
    	if (k < 1) return head;
        ListNode* last = NULL;
        ListNode* newhead = NULL;
        ListNode* cur = head;
        bool fullcut = false;
        while (cur != NULL) {
            ListNode* remain_head = cut(cur, k, fullcut);
            ListNode* rtail = cur;
            ListNode* rhead = fullcut ? reverse(cur) : cur;
            cur = remain_head;
            if (newhead == NULL) {
                newhead = rhead;
            } else {
                last->next = rhead;
            }
            last = rtail;
        }
        
        return newhead;
    }
    
    ListNode* cut(ListNode* head, int k, bool &full) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        while (k > 0 && cur != NULL) {
            k--;
			pre = cur;
            cur = cur->next;
        }
        if (pre != NULL) pre->next = NULL;
        full = k == 0;
        return cur;
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

void print(ListNode* head) {
	while (head != NULL) {
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}

int main() {
	ListNode nodes[7];
	int len = sizeof(nodes) / sizeof(ListNode);
	
	for (int i=0; i<len - 1; i++) {
		nodes[i].next = &nodes[i+1];
		nodes[i].val = i + 1;
	}
	nodes[len - 1].val = len;
	
	Solution s;
	
	print(&nodes[0]);
	
	ListNode* res = s.reverseKGroup(&nodes[0], 4);
	
	print(res);
	
	system("pause");
	return 0;
}

