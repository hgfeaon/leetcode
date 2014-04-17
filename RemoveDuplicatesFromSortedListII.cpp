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
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *tail = NULL, *h = NULL, *cur = head->next;
        ListNode *prev = head;
        
        bool nodup = true;

        while (cur != NULL) {
            if (cur->val != prev->val) {
                if (nodup) {
                    if (h == NULL) {
                        h=tail=prev;
                    } else {
                        tail->next = prev;
                        tail = prev;
                    }
                    tail->next = NULL;
                } else {
                    nodup = true;   // reset the flag
                }
            } else {
                nodup = false;
            }
            prev = cur;
            cur = cur->next;
        }

        if (nodup) {
            if (h == NULL) {
                h = prev;
            } else {
                tail->next = prev;
            }
        }
        return h;
    }
};

int main() {

	system("pause");
	return 0;
}

