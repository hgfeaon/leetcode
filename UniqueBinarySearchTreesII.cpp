#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	vector<TreeNode *> res;
public:
    vector<TreeNode *> generateTrees(int n) {
        res.clear();
        res = dfs(1, n + 1);
        return res;
    }

    vector<TreeNode*> dfs(int start, int end) {
		vector<TreeNode*> res;
		if (start >= end) {
			res.push_back(NULL);
			return res;
		}
		TreeNode* rt = NULL;
		for (int i=start; i<end; i++) {
			vector<TreeNode*> lsub = dfs(start, i);
			vector<TreeNode*> rsub = dfs(i+1, end);

			for (int li=0; li<lsub.size(); li++) {
				for (int ri=0; ri<rsub.size(); ri++) {
					rt = new TreeNode(i);
					rt->left = lsub[li];
					rt->right= rsub[ri];
					res.push_back(rt);
				}
			}
		}
		return res;
    }
};

void print(TreeNode* root) {
	if (root == NULL) {
		cout<<"empty"<<endl;
		return;
	}
	vector<TreeNode*> level1(1, root);
	vector<TreeNode*> level2;

	while (!level1.empty()) {
		int pn = level1.size();
		for (int i=0; i<pn; i++) {
			cout<<level1[i]->val<<" ";
			if (level1[i]->left != NULL) level2.push_back(level1[i]->left);
			if (level1[i]->right!= NULL) level2.push_back(level1[i]->right);
		}
		level1.clear();
		swap(level1,level2);
		cout<<endl;
	}
}

int main() {
	Solution s;

	vector<TreeNode*> res = s.generateTrees(4);

	for (int i=0; i<res.size(); i++) {

		print(res[i]);
		cout<<endl;
	}

	system("pause");
	return 0;
}

