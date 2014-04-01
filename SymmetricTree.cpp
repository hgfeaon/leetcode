#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

typedef struct TagTreeNode TreeNode;
struct TagTreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TagTreeNode(int x = 0) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return dfs(root->left, root->right);
    }
    
    bool dfs(TreeNode* curnode, TreeNode* symnode) {
        if (curnode == NULL && symnode == NULL) return true;
        if (curnode != NULL && symnode != NULL && curnode->val == symnode->val) {
            return dfs(curnode->left, symnode->right) && dfs(curnode->right, symnode->left);
        }
        return false;
    }
    
    bool _isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        vector<TreeNode*> sa;
        vector<TreeNode*> sb;
        sa.push_back(root->left);
        sb.push_back(root->right);

        while (!sa.empty() && !sb.empty()) {
            TreeNode* anode = sa.back();
            TreeNode* bnode = sb.back();

            sa.pop_back();
            sb.pop_back();
            
            if (anode == NULL && bnode == NULL) {
                continue;
            }
            
            if (anode != NULL && bnode != NULL && anode->val == bnode->val) {
                sa.push_back(anode->left);
                sb.push_back(bnode->right);

                sa.push_back(anode->right);
                sb.push_back(bnode->left);
            } else {
                return false;
            }
        }
        if (sa.size() != sb.size()) return false;
        return true;
    }
};

int main() {
    TreeNode nodes[10];
    for (int i=0; i<10; i++) {
        nodes[i].val = i;
        nodes[i].left = NULL;
        nodes[i].right = NULL;
    }
    nodes[2].val = 1;
    nodes[0].left = &nodes[1];
    nodes[0].right= &nodes[2];
    nodes[4].val = 4;
    nodes[1].right = &nodes[3];
    nodes[2].left  = &nodes[4];

    
    Solution s;
    cout<<s.isSymmetric(&nodes[0])<<endl;
    cout<<s._isSymmetric(&nodes[0])<<endl;
	system("pause");
	return 0;
}