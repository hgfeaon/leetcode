#include <iostream>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = 0) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* last;
public:
    void flatten(TreeNode *root) {
        last = NULL;
        dfs(root);
        last->right = NULL;
    }

    void dfs(TreeNode* root) {
        if (root == NULL) return;
        TreeNode* L = root->left;
        TreeNode* R = root->right;

        root->left = last;
        if (last != NULL) last->right = root;
        last = root;

        if (L != NULL) dfs(L);
        if (R != NULL) dfs(R);
    }
};


void print(TreeNode* start) {
    TreeNode* pre = NULL;
    while (start != NULL) {
        cout<<start->val<<" ";
        pre = start;
        start = start->right;
    }
    cout<<endl;
    while (pre != NULL) {
        cout<<pre->val<<" ";
        pre = pre->left;
    }
}


int main() {
    TreeNode nodes[10];
    //nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[4];
    
    //nodes[4].right = &nodes[5];
    
    //nodes[1].left = &nodes[2];
    //nodes[1].right= &nodes[3];
    
    
    for (int i=0; i<10; i++) nodes[i].val = i + 1;

    Solution s;

    s.flatten(&nodes[0]);
    
    print(&nodes[0]);
    
	system("pause");
	return 0;
}

