#include <iostream>
#include <cstdlib>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int sum;
public:
    int sumNumbers(TreeNode *root) {
        sum = 0;
        dfs(root, 0);
        return sum;
    }
    
    void dfs(TreeNode* root, int cur) {
		if (root == NULL) return;
		
		cur = cur * 10 + root->val;
		
		if (root->left == NULL && root->right == NULL) {
			sum += cur;
			return;
		}
		
		dfs(root->left, cur);
		dfs(root->right, cur);
	}
};

int main() {
	TreeNode n1(1), n2(2), n3(3), n4(4);
	n1.left = &n2;
	Solution s;
	cout<<s.sumNumbers(&n1)<<endl;
	system("pause");
	return 0;
}

