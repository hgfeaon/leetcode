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
    ListNode *_sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *h1 = NULL, *h2 = NULL, *cur = head;
        ListNode *tail1 = h1, *tail2 = h2;

        int count = 0;
        while (cur != NULL) {
            if (++count & 0x1) {
                if (h1 == NULL) {
                    tail1 = h1 = cur;
                } else {
                    tail1->next = cur;
                    tail1 = cur;
                }
            } else {
                if (h2 == NULL) {
                    tail2 = h2 = cur;
                } else {
                    tail2->next = cur;
                    tail2 = cur;
                }
            }
            cur = cur->next;
        }
        if (h1 != NULL) tail1->next = NULL;
        if (h2 != NULL) tail2->next = NULL;

        h1 = sortList(h1);
        h2 = sortList(h2);
        
        return merge(h1, h2);
    }
    
    ListNode *sortList(ListNode *head) {
        if (head == NULL) return head;
        ListNode* cur = head;
        int count = 1;
        while ((cur = cur->next) != NULL) count++;


        return sortListN(head, count);
    }
    
    ListNode* sortListN(ListNode *head, int n) {
        if (n < 2) return head;
        ListNode *h1, *h2, *cur;
        int k = n >> 1;
        cur = head;
        while (--k) cur = cur->next;
        h1 = head;
        h2 = cur->next;
        cur->next = NULL;

        h1 = sortListN(h1, n>>1);
        h2 = sortListN(h2, n - (n>>1));

        return merge(h1, h2);
    }
    
    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode *new_head = NULL, *new_tail = NULL, *cur;

        while (h1 != NULL && h2 != NULL) {
            if (h1->val < h2->val) {
                cur = h1;
                h1 = h1->next;
            } else {
                cur = h2;
                h2 = h2->next;
            }
            if (new_head == NULL) {
                new_head = new_tail = cur;
            } else {
                new_tail->next = cur;
                new_tail = cur;
            }
        }
        while (h1 != NULL) {
            new_tail->next = h1;
            new_tail = h1;
            h1 = h1->next;
        }
        while (h2 != NULL) {
            new_tail->next = h2;
            new_tail = h2;
            h2 = h2->next;
        }
        return new_head;
    }
};

void print_list(ListNode* head) {
    while (head != NULL) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main() {
    ListNode na(2), nb(1);
    na.next = &nb;
    
    print_list(&na);
    Solution s;
    ListNode* ret = s.sortList(&na);

    print_list(ret);
	system("pause");
	return 0;
}

