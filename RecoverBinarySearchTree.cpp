#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x = 0) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* pre;
    TreeNode* first;
    TreeNode* second;
public:
    void recoverTree(TreeNode *root) {
        nodes.clear();
        pre = first = second = NULL;
        dfs(root);
        // case a. 1 5 3 4 2 6 7
        // case b. 1 3 2 4
        // case c. 3 2
        // case d. 3
        // case e. NULL
        if (second == NULL) return; // case (d,e)
        int t = first->val;
        first->val = second->val;
        second->val= t;
    }
    
    void dfs(TreeNode* root) {
        if (root == NULL) return;
        dfs(root->left);
        visit(root);
        dfs(root->right);
    }
    
    void visit(TreeNode* node) {
        if (pre == NULL) {
            pre = node;
            return;
        }
        if (node->val < pre->val) {
            if (first == NULL) {
                first = pre;
                second= node;   // assume swap with node next to pre(case b,c)
            } else {
                second= node;   // fix above assumption(case a)
            }
        }
        pre = node;
    }
};

class Solution2 {
private:
    vector<TreeNode*> nodes;
public:
    void recoverTree(TreeNode *root) {
        nodes.clear();
        dfs(root);
        // 1 5 3 4 2 6 7
        // 1 3 2 4
        // 3 2
        int len = nodes.size();
        if (len < 1) return;
        
        int pre = nodes[0]->val;
        int cur = 0;
        int first = -1;
        int second= -1;
        for (int i=1; i<len; i++) {
            cur = nodes[i]->val;
            if (cur < pre) {
                if (first < 0) {
                    first = i-1;
                } else {
                    second= i;
                }
            }
            pre = cur;
        }
        if (second < 0) second = first + 1;
        int t = nodes[first]->val;
        nodes[first]->val = nodes[second]->val;
        nodes[second]->val= t;
    }
    
    void dfs(TreeNode* root) {
        if (root == NULL) return;
        dfs(root->left);
        nodes.push_back(root);
        dfs(root->right);
    }
};

int main() {

	system("pause");
	return 0;
}

