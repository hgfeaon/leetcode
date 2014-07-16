#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = 0) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int ilen = inorder.size();
        int plen = postorder.size();

        if (ilen == 0 || plen == 0) return NULL;
        return dfs(inorder, postorder, 0, ilen, plen - 1, -1);
    }

    TreeNode* dfs(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe) {
        
        if (is >= ie || ps <= pe) return NULL;
        int rval = postorder[ps];
        int iroot= is;

        while (iroot != ie && inorder[iroot] != rval) iroot++;

        int left_len = iroot - is;
        
        TreeNode* nroot = new TreeNode(rval);

        nroot->left = dfs(inorder, postorder, is, iroot, pe + left_len, pe);
        nroot->right= dfs(inorder, postorder, iroot + 1, ie, ps - 1, pe + left_len);

        return nroot;
    }
};

int main() {

    int pod[] = {1};
    int iod[] = {1};

    int len = sizeof(pod) / sizeof(int);

    vector<int> postorder(pod, pod + len);
    vector<int> inorder(iod, iod + len);

    Solution s;
    TreeNode *root = s.buildTree(inorder, postorder);
    if (root != NULL) {
        TreeNode* left = root->left;
        TreeNode* right= root->right;
    }
    
	system("pause");
	return 0;
}

