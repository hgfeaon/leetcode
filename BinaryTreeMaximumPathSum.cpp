#include <iostream>
#include <cstdlib>
#include <utility>

using namespace std;

typedef struct tagTreeNode TreeNode;

struct tagTreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    tagTreeNode(int x=0) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int max_path;
public:
    int maxPathSum(TreeNode *root) {
        int s, m;
        dfs(root, s, m);
        return (m > s) ? m : s;
    }
    
    void dfs(TreeNode* root, int& sole, int& misc) {
        if (root == NULL) {
            sole = INT_MIN;
            misc = INT_MIN;
            return;
        }
        int ls, lm, rs, rm, ms, mm;
        dfs(root->left, ls, lm);
        dfs(root->right, rs, rm);
        
        ms = (ls > rs) ? ls : rs;
        mm = (lm > rm) ? lm : rm;
        
        sole = root->val + (ms < 0 ? 0 : ms);
        int m = ((ls < 0 ? 0 : ls) + (rs < 0 ? 0 : rs) + root->val);
        misc = mm > m ? mm : m;
    }
    
    int _maxPathSum(TreeNode *root) {
        max_path = INT_MIN;
        _dfs(root);
        return max_path;
    }
    
    int _dfs(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int ls = _dfs(root->left);
        int rs = _dfs(root->right);
        
        int ms = (ls > rs) ? ls : rs;
        
        int sole = root->val + (ms < 0 ? 0 : ms);
        
        int m = ((ls < 0 ? 0 : ls) + (rs < 0 ? 0 : rs) + root->val);
        
        if (m > max_path) max_path = m;
        
        return sole;
    }
};

int main() {
    TreeNode nodes[10];
    for (int i=0; i<10; i++) {
        nodes[i].val = i+1;
        nodes[i].left = NULL;
        nodes[i].right = NULL;
    }
    nodes[0].left = &nodes[1];
    nodes[1].right= &nodes[7];
    nodes[1].left = &nodes[8];
    
    nodes[0].right = &nodes[2];
    
    nodes[5].val = -3;;

    Solution s;
    cout<<s.maxPathSum(&nodes[0])<<endl;
    system("pause");
    return 0;    
}
