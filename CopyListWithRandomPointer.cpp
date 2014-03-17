#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;
struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
 
class Solution {
public:
    // 1. with a map
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> p2p;
        
        RandomListNode* newhead = new RandomListNode(head->label);
        newhead->random = head->random;
        p2p.insert(pair<RandomListNode*, RandomListNode*>(head, newhead));
        
        RandomListNode* tail = newhead;
        head = head->next;
        
        while (head != NULL) {
            RandomListNode* item = new RandomListNode(head->label);
            item->random = head->random;
            p2p.insert(pair<RandomListNode*, RandomListNode*>(head, item));
            
            tail->next = item;
            tail = item;
            head = head->next;
        }
        
        tail = newhead;
        while (tail != NULL) {
            if (tail->random != NULL) {
                tail->random = p2p.find(tail->random)->second;
            }
            tail = tail->next;
        }
        return newhead;
    }
    
    // 2. without a map
    RandomListNode *_copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        
        RandomListNode* item = new RandomListNode(head->label);
        item->random = head->random;
        item->next = head->next;
        head->next = item;
        
        RandomListNode* tail = item->next;
        
        while (tail != NULL) {
            item = new RandomListNode(tail->label);
            item->random = tail->random;
            item->next = tail->next;
            tail->next = item;
            
            tail = item->next;
        }
        tail = head;
        while (tail != NULL) {
            tail = tail->next;
            if (tail->random != NULL) tail->random = tail->random->next;
            tail = tail->next;
        }
        
        RandomListNode* newhead = head->next;
        RandomListNode* oldtail = head;
        tail = newhead;
        while (tail->next != NULL) {
            oldtail->next = tail->next;
            oldtail = tail->next;
            tail->next = oldtail->next;
            tail = oldtail->next;
        }
        oldtail->next = NULL;
        return newhead;
    }
};

void print_list(RandomListNode* head) {
    while (head != NULL) {
        cout<<head->label;
        if (head->next == NULL) {
            cout<<", next=null";
        } else {
            cout<<", next="<<head->next->label;
        }
        if (head->random == NULL) {
            cout<<", rnd=null";
        } else {
            cout<<", rnd="<<head->random->label;
        }
        cout<<endl;
        head = head->next;
    }
}

int main() {
    RandomListNode* items[10];
    for (int i=0; i<10; i++) {
        items[i] = new RandomListNode(i);
    }
    
    for (int i=0; i<9; i++) {
        items[i]->next = items[i+1];
    }
    items[2]->random = items[4];
    items[5]->random = items[1];
    items[8]->random = items[3];
    
    print_list(items[0]);
    Solution s;
    RandomListNode* ret = s._copyRandomList(items[0]);
    
    cout<<"==="<<endl;
    print_list(ret);
    return 0;
}
