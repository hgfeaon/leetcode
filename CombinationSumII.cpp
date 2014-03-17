#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        
        vector<vector<int> > tmp;
        vector<int> sel;
        dfs(num, 0, target, sel, tmp);
        return tmp;
    }
    
    void dfs(vector<int> &num, int pos, int target, vector<int>& sel, vector<vector<int> >& res) {
        if (target == 0) {
            res.push_back(sel);
            return;
        }
        if (pos >= num.size()) return;
        int cur = num[pos];
        int dup = 0;        
        int i = pos;
        while (++i < num.size() && num[i] == cur) dup++;
        
        int add = 0;

        for (i = 0; (i <= dup + 1) && add <= target; i++, add+=cur) {
            if (i != 0) {
                sel.push_back(cur);
            }
            dfs(num, pos + dup + 1, target - add, sel, res);
        }
        for (i = add/cur - 1; i>0; i--) sel.pop_back();
    }
    
};

void print(vector<vector<int> > data) {
    for (int i=0; i<data.size(); i++) {
        vector<int>& row = data[i];
        for (int j=0; j<row.size(); j++) {
            cout<<row[j]<<", ";
        }
        cout<<endl;
    }
}
 
int main() {
    Solution s;
    int cands[] = {10,1,1,7,6,1,5};
    vector<int> candidates(cands, cands + sizeof(cands) / sizeof(int));
    vector<vector<int> > res = s.combinationSum2(candidates, 6);
    print(res);
    return 0;
}
