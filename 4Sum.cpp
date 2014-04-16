#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        vector<int> r;
        r.resize(4);
        sort(num.begin(), num.end());
        
        int len = num.size();
        for (int i=0; i<len; i++) {
            if (i!=0 && num[i] == num[i-1]) continue;   // skip dup
            for (int j=i+1; j<len; j++) {
                int psum = num[i] + num[j];
                if (num[j] >= 0 && psum > target) break;
                if (j!=i+1 && num[j] == num[j-1]) continue; // skip dup
                r[0] = num[i], r[1] = num[j];
                
                int ptarget = target - psum;

                int p = j+1;
                int q = len - 1;
                while (p < q) {
                    if (num[p] >= 0 && num[p] > ptarget) break;
                    if (num[q] < 0 && num[p] < ptarget) {
                        break;
                    }
                    if (p != j+1 && num[p] == num[p-1]) {   // skip dup
                        p++;
                        continue;
                    }
                    if (q != len-1 && num[q] == num[q+1]) { // skip dup
                        q--;
                        continue;
                    }
                    int s = num[p] + num[q];
                    if (s < ptarget) {
                        p++;
                    } else if (s > ptarget) {
                        q--;
                    } else {
                        r[2] = num[p];
                        r[3] = num[q];
                        res.push_back(r);
                        p++, q--;
                    }
                }
            }
        }
        return res;
    }
};

void print(vector<vector<int> >& res) {
    for (int i=0; i<res.size(); i++){
        for (int j=0; j<res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int nums[] = {6,-10,-7,-4,9,-10,-2,-1,5,3};
    int sn = sizeof(nums) / sizeof(int);

    vector<int> S(nums, nums+sn);
    vector<vector<int> > res;
    
    Solution s;
    res = s.fourSum(S, -26);
    print(res);
	system("pause");
	return 0;
}

