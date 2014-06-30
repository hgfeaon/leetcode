class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (step(fast, 2) && step(slow, 1)) {
            if (fast == slow) break;
        }
        if (fast == NULL) {
            return NULL;
        }
        ListNode* fake_end = slow;

        ListNode* h2 = fake_end->next;
        ListNode* h1 = head;

        ListNode* cur1 = h1;
        ListNode* cur2 = h2;

        int len1 = 0, len2 = 0;

        while (cur1 != fake_end) len1++, cur1 = cur1->next;
        while (cur2 != fake_end) len2++, cur2 = cur2->next;

        if (len1 == len2) {
            len1 = len2 = 0;
        } else if (len1 > len2) {
            len1 = len1 - len2;
            len2 = 0;
        } else {
            len1 = 0;
            len2 = len2 - len1;
        }

        step(h1, len1);
        step(h2, len2);

        while (h2 != h1 && step(h1, 1) && step(h2, 1));

        return h1;
    }

    bool step(ListNode* &cur, int n) {
        while (cur != NULL && n > 0) {
            n--;
            cur = cur->next;
        }
        return n == 0;
    }
};
