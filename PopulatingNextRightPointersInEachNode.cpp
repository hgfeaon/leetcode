#include <iostream>
#include <cstdlib>
class Solution {
public:
    void connect(TreeLinkNode *root) {
        dfs(root, NULL);
    }

    void dfs(TreeLinkNode* root, TreeLinkNode* counter_part_root) {
        if (root == NULL) return;
        root->next = counter_part_root;
        dfs(root->left, root->right);
        dfs(root->right, counter_part_root == NULL ? NULL:counter_part_root->left);
    }
};

int main() {

	system("pause");
	return 0;
}

