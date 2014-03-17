#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        
        vector<vector<int> > tmp;
        vector<int> sel;
        
        comsum(candidates, 0, target, sel, tmp);
        return tmp;
    }
    
    void comsum(vector<int>& nums, int pos, int tar, vector<int>& sel, vector<vector<int> >& res) {
        if (tar == 0) {
            res.push_back(sel);
            return;
        }
        if (pos >= nums.size()) return;
        int cur = nums[pos];
        int add = 0;
        for (add = 0; add <= tar; add+=cur) {
            if (add != 0) {
                sel.push_back(cur);
            }
            comsum(nums, pos + 1, tar - add, sel, res);
        }
        for (int i = add/cur - 1; i>0; i--) {
            sel.pop_back();
        }
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
    int cands[] = {1,2,3,1};
    vector<int> candidates(cands, cands + sizeof(cands) / sizeof(int));
    vector<vector<int> > res = s.combinationSum(candidates, 4);
    print(res);
    return 0;
}
