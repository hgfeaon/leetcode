#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    TreeNode* current;
    stack<TreeNode*> nodeStack;
public:
    BSTIterator(TreeNode *root) {
        current = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (nodeStack.empty() && current == NULL) {
            return false;
        } else {
            return true;
        }
    }

    /** @return the next smallest number */
    int next() {
        while (current != NULL) {
            nodeStack.push(current);
            current = current->left;
        }
        // node current must be null,
        // the last one pushed in the stack must be the smallest one
        
        TreeNode* last = nodeStack.top();
        nodeStack.pop();
        
        // next we will start from its right sub-tree to find the smallest one
        current = last->right;

        return last->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
 

int main() {

	system("pause");
	return 0;
}

