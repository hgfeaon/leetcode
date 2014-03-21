#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

typedef struct TagTreeNode TreeNode;

struct TagTreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TagTreeNode(int x=0) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL) return res;
        vector<TreeNode*> stack;
        stack.push_back(root);
        while(!stack.empty()){
            TreeNode* n = stack.back();
            stack.pop_back();
            res.push_back(n->val);
            if (n->right != NULL) stack.push_back(n->right);
            if (n->left != NULL) stack.push_back(n->left);
        }
    }
};

int main() {
    // NO IMPLEMENTATION
	system("pause");
	return 0;
}

