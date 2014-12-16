#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena = count(headA);
        int lenb = count(headB);
        int diff = 0;
        ListNode* longer = NULL;
        ListNode* shorter= NULL;
        if (lena > lenb) {
            diff = lena - lenb;
            longer = headA;
            shorter= headB;
        } else {
            diff = lenb - lena;
            longer = headB;
            shorter= headA;
        }
        longer = forward(longer, diff);

        while (longer != shorter) {
            longer = forward(longer, 1);
            shorter= forward(shorter, 1);
        }
        return longer;
    }
    ListNode* forward(ListNode* head, int step) {
        while(head != NULL) {
            if (step-- <= 0) {
                break;
            }
            head = head->next;
        }
        return head;
    }
    int count(ListNode* head) {
        int res = 0;
        while (head != NULL) {
            head = head->next;
            res++;
        }
        return res;
    }
};

int main() {
    ListNode n1(1);
    ListNode n2(2);
    Solution s;
    ListNode* res = s.getIntersectionNode(&n1, &n1);
    if (res == NULL) {
        cout<<"null"<<endl;
    } else {
        cout<<res->val<<endl;
    }
	system("pause");
	return 0;
}

