#include <iostream>
#include <vector>

using namespace std;

typedef struct TagTreeNode TreeNode;
struct TagTreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TagTreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    // do iteratively
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> path;
        vector<TreeNode*> stack;
        if (root != NULL) {
            stack.push_back(root);
        }
        TreeNode* last = NULL;
        
        while(!stack.empty()) {
            TreeNode* cur = stack.back();
            
            if (cur->left == NULL && cur->right == NULL) {
                path.push_back(cur->val);
                stack.pop_back();
                last = cur;
                continue;
            }
            
            if (last != NULL && (cur->left == last || cur->right == last)) {
                path.push_back(cur->val);
                stack.pop_back();
                last = cur;
                continue;
            }
            
            while (cur != NULL) {
                if (cur->right != NULL) stack.push_back(cur->right);
                if (cur->left != NULL) stack.push_back(cur->left);
                cur = cur->left;
            }
        }
        
        return path;
    }
};

int main() {
    // NO IMPLEMENTATION
    return 0;    
}
