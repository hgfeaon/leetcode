#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

typedef struct TagTreeNode TreeNode;
struct TagTreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        bool use_dfs = false;
        if (use_dfs) {
            int min_depth = INT_MAX;
            dfs(root, 0, min_depth);
            return min_depth + 1;
        } else {
            return bfs(root) + 1;
        }
    }
    
    void dfs(TreeNode *root, int cur_depth, int& min_depth) {
        if (root == NULL) return;
        if (cur_depth >= min_depth) return;
        // we come here means that cur_depth < min_depth
        if (root->left == NULL && root->right == NULL) { // this is a leaf node
            min_depth = cur_depth;
            return;
        }
        
        dfs(root->left, cur_depth + 1, min_depth);
        dfs(root->right, cur_depth + 1, min_depth);
    }
    
    int bfs(TreeNode *root) {
        if (root == NULL) return 0;
        int depth = 0; 
        int cur_len = 1;
        queue<TreeNode*> q;
        q.push(root);
        bool hasleft = false;
        bool hasright= false; 
        while (!q.empty()) {
            while(cur_len--) {
                TreeNode* n = q.front();
                q.pop();
                hasleft = n->left != NULL;
                hasright= n->right != NULL;
                if (hasleft) {
                    q.push(n->left);
                }
                if (hasright) {
                    q.push(n->right);
                }
                if (!hasleft && !hasright) return depth;
            }
            depth++;
            cur_len = q.size();
        }
        return depth;
    }
};

int main() {
    TreeNode nodes[10];
    for (int i=0; i<10; i++) {
        nodes[i].val = i;
        nodes[i].left = NULL;
        nodes[i].right = NULL;
    }
    nodes[0].left = &nodes[1];
    nodes[1].right= &nodes[2];
    
    nodes[2].left = &nodes[3];
    nodes[3].right= &nodes[4];
    
    Solution s;
    cout<<s.minDepth(&nodes[0])<<endl;
    return 0;
}
