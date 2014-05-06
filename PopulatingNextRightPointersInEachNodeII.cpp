#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        queue<TreeLinkNode*> que;
        que.push(root);
        int level_count = 1;
        while (level_count > 0) {
            while (level_count--) {
                TreeLinkNode* cur = que.front();
                que.pop();
                if (level_count == 0) {
                    cur->next = NULL;
                } else {
                    cur->next = que.front();
                }
                if (cur->left != NULL) {
                    que.push(cur->left);
                }
                if (cur->right != NULL) {
                    que.push(cur->right);
                }
            }
            level_count = que.size();
        }
    }
    
    void connect2(TreeLinkNode *root) {
        TreeLinkNode* next_level_head = root;
        TreeLinkNode* level_cur;
        TreeLinkNode* next_level_pre;
        TreeLinkNode* next_level_cur;
        
        int stage = 0;
        
        while (next_level_head != NULL) {
            level_cur = next_level_head;
            next_level_head = NULL;
            next_level_pre  = NULL;
            next_level_cur  = NULL;
            stage = 0;
            while (level_cur != NULL) {
                if (stage == 2) {
                    level_cur = level_cur->next;
                    stage = 0;
                    continue;
                }
                if (stage == 1) {
                    stage++;
                    next_level_cur = level_cur->right;
                }
                if (stage == 0) {
                    stage++;
                    next_level_cur = level_cur->left;
                }
                if (next_level_cur == NULL) continue;
                
                if (next_level_head == NULL) {
                    next_level_head = next_level_cur;
                }
                if (next_level_pre != NULL) {
                    next_level_pre->next = next_level_cur;
                }
                next_level_pre = next_level_cur;
            }
        }
    }
};

int main() {

    TreeLinkNode root(1);
    TreeLinkNode left(2);
    TreeLinkNode right(2);

    root.left = &left;
    root.right= &right;
    
    Solution s;

    s.connect2(&root);
    cout<<left.next<<endl;
	system("pause");
	return 0;
}

