#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>

using namespace std;

typedef struct tagTreeNode TreeNode;

struct tagTreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    tagTreeNode(int x=0) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL) return res;
        vector<pair<TreeNode*, bool> > stack;
        stack.push_back(make_pair(root, false));
        
        while (!stack.empty()) {
            pair<TreeNode*, bool>& pn = stack.back();
            TreeNode* n = pn.first;
            if (pn.second) {
                stack.pop_back();
                res.push_back(n->val);
                if (n->right != NULL) {
                    stack.push_back(make_pair(n->right, false));
                }
                continue;
            }
            pn.second = true;
            n = n->left;
            while (n != NULL) {
                stack.push_back(make_pair(n, true));
                n = n->left;
            }
        }
    }
    
    // a version can be adopt to postorder traversal
    vector<int> __inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL) return res;
        vector<pair<TreeNode*, bool> > stack;
        stack.push_back(make_pair(root, false));
        
        while (!stack.empty()) {
            pair<TreeNode*, bool>& pn = stack.back();
            TreeNode* n = pn.first;
            stack.pop_back();
            
            if (pn.second) {
                res.push_back(n->val);
            } else {
                if (n->right != NULL) {
                    stack.push_back(make_pair(n->right, false));
                }
                stack.push_back(make_pair(n, true));
                if (n->left != NULL) {
                    stack.push_back(make_pair(n->left, false));    
                }
            }
        }
        return res;
    }
    
    // better one but only for inorder
    vector<int> _inorderTraversal(TreeNode *root) {
        vector<int> res;
        vector<TreeNode*> stack;
        
        while(root != NULL || !stack.empty()) {
                while (root != NULL) {
                    stack.push_back(root);    
                    root=root->left;
                }
                if (!stack.empty()) {
                    root = stack.back();
                    stack.pop_back();
                    res.push_back(root->val); 
                    root = root->right;   
                }
        }
        return res;
    }
};

int main() {
    TreeNode nodes[10];
    for (int i=0; i<10; i++) {
        nodes[i].val = i;
        nodes[i].left = NULL;
        nodes[i].right = NULL;
    }
    nodes[0].left = &nodes[1];
    // nodes[0].right= &nodes[2];

    nodes[1].right = &nodes[3];
    // nodes[1].right= &nodes[4];

    Solution s;
    vector<int> res = s.__inorderTraversal(&nodes[0]);
    
    for (int i=0; i<res.size(); i++) {
        cout<<res[i]<<",";
    }
    
	system("pause");
	return 0;
}
