#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x = 0) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode *clone = dfs(node);
        dfs_clear(node);
        return clone;
    }
    
    UndirectedGraphNode *dfs(UndirectedGraphNode *orgin) {
        if (orgin == NULL) return NULL;
        UndirectedGraphNode *clone = get_clone_node(orgin);
        if (clone != NULL) return clone;
        // cout<<"cloning node :"<<orgin->label<<endl;
        int olen = orgin->neighbors.size();
        
        clone = add_clone_node(orgin);
        
        for (int i=0; i<olen; i++) {
            UndirectedGraphNode *nb = orgin->neighbors[i];
            clone->neighbors.push_back(dfs(nb));
        }
        return clone;
    }
    
    void dfs_clear(UndirectedGraphNode *node) {
        UndirectedGraphNode *clone = get_clone_node(node);
        if (clone == NULL) return;
        // cout<<"clear node: "<<node->label<<endl;
        del_clone_node(node);
        
        int len = node->neighbors.size();
        
        for (int i=0; i<len; i++) {
            dfs_clear(node->neighbors[i]);
        }
    }
    
    UndirectedGraphNode *get_clone_node(UndirectedGraphNode *node) {
        int len;
        // cout<<"get info of cloned node : "<<node->label<<endl;
        if (node == NULL || (len = node->neighbors.size()) < 2
            || node->neighbors[len - 2] != NULL) return NULL;
        return node->neighbors[len - 1];
    }
    
    UndirectedGraphNode *add_clone_node(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        // cout<<"append link for cloned node: "<<node->label<<endl;
        node->neighbors.push_back(NULL);
        node->neighbors.push_back(new UndirectedGraphNode(node->label));
        return node->neighbors.back();
    }
    
    void del_clone_node(UndirectedGraphNode *node) {
        if (get_clone_node(node) == NULL) return;
        // cout<<"del clone link for node:"<<node->label<<endl;
        node->neighbors.pop_back(); // cloned node addr
        node->neighbors.pop_back(); // null
    }
};

class Solution2 {
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> o2n;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        o2n.clear();
        UndirectedGraphNode *clone = dfs(node);
        return clone;
    }
    
    UndirectedGraphNode *dfs(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>::iterator iter = o2n.find(node);
        if (iter != o2n.end()) return iter->second;
        
        UndirectedGraphNode *clone = new UndirectedGraphNode(node->label);
        o2n.insert(make_pair(node, clone));
        
        int len = node->neighbors.size();
        
        for (int i=0; i<len; i++) {
            clone->neighbors.push_back(dfs(node->neighbors[i]));
        }
    }
    return clone;
};


void join(UndirectedGraphNode &a, UndirectedGraphNode &b) {
    a.neighbors.push_back(&b);
    b.neighbors.push_back(&a);
}

int main() {
    UndirectedGraphNode a(-1), b(2), c(3), d(4);

    //join(a, b);
    //join(b, c);
    //join(c, d);
    //join(d, a);
    
    Solution s;
    
    s.cloneGraph(&a);

	system("pause");
	return 0;
}

