#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
Definition for binary tree
class TreeNode {
public:
   	int val;
   	TreeNode *left;
   	TreeNode *right;
   	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
    vector<vector<int> > result;
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        result.clear();
        vector<int> path;
        dfs(root, path, sum);
        return result;
    }
    
    void dfs(TreeNode *root, vector<int>& path, int sum) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL && root->val == sum) {
            path.push_back(root->val);
            result.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        dfs(root->left, path, sum - root->val);
        dfs(root->right, path, sum - root->val);
        path.pop_back();
    }
};

int main() {

	system("pause");
	return 0;
}

