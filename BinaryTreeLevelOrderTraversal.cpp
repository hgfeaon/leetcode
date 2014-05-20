#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int> > nodes;
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        nodes.clear();
        dfs(root, 0);
        return nodes;
    }

    void dfs(TreeNode* root, int level) {
        if (root == NULL) return;
        if (level >= nodes.size()) {
            nodes.push_back(vector<int>());
        }
        nodes[level].push_back(root->val);
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
};

int main() {

	system("pause");
	return 0;
}

