#include <iostream>
#include <cstdlib>

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
    bool hasPathSum(TreeNode *root, int sum) {
        return dfs(root, 0, sum);
    }
    
    bool dfs(TreeNode* root, int cur_sum, int target) {
        if (root == NULL) return false;
        cur_sum = cur_sum + root->val;
        if (cur_sum == target && root->left == NULL && root->right == NULL) return true;
        if (dfs(root->left, cur_sum, target)) return true;
        if (dfs(root->right, cur_sum, target)) return true;
        return false;
    }
};

int main() {
    TreeNode nodes[10];
    for (int i=0; i<10; i++) {
        nodes[i].val = i+1;
        nodes[i].left = NULL;
        nodes[i].right = NULL;
    }
    nodes[0].right = &nodes[1];
    //nodes[1].right = &nodes[3];
    //nodes[1].left = &nodes[5];
    
    Solution s;
    cout<<s.hasPathSum(&nodes[0], 3)<<endl;
	system("pause");
	return 0;
}

