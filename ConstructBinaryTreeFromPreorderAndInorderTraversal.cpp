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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int plen = preorder.size();
        int ilen = inorder.size();
        if (plen == 0 || ilen == 0) return NULL;
        return dfs(preorder, inorder, 0, plen, 0, ilen);
    }

    TreeNode* dfs(vector<int> &preorder, vector<int> &inorder, int ps, int pe, int is, int ie) {
        if (ps >= pe || is >= ie) return NULL;

        int rval = preorder[ps];
        int iroot= is;
        cout<<rval<<endl;
        while (iroot != ie && inorder[iroot] != rval) iroot++;

        int pe_offset = (iroot - is) + ps + 1;

        TreeNode* nroot = new TreeNode(rval);

        nroot->left = dfs(preorder, inorder, ps + 1, pe_offset, is, iroot);
        nroot->right= dfs(preorder, inorder, pe_offset, pe, iroot + 1, ie);

        return nroot;
    }
};

int main() {
    int pod[] = {2};
    int iod[] = {2};

    int len = sizeof(pod) / sizeof(int);

    vector<int> preorder(pod, pod + len);
    vector<int> inorder(iod, iod + len);

    Solution s;
    TreeNode *root = s.buildTree(preorder, inorder);
    if (root != NULL) {
        TreeNode* left = root->left;
        TreeNode* right= root->right;
    }
	system("pause");
	return 0;
}

