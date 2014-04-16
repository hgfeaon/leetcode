#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        int len = num.size();
        sort(num.begin(), num.end());
        vector<int> tmp(3, 0);
        for (int i=0; i<len; i++) {
            tmp[0] = num[i];
            if (i != 0 && num[i] == num[i-1]) continue; // skip dup
            int rs = 0 - num[i];
            int p = i + 1, q = len - 1;
            while (p<q) {
                if (p != i+1 && num[p] == num[p-1]) {
                    p++;
                    continue;   // skip dup
                }
                if (q != len-1 && num[q] == num[q+1]) {
                    q--;
                    continue;   // skip dup
                }
                int s = num[p] + num[q];
                if (s < rs) {
                    p++;
                } else if (s > rs) {
                    q--;
                } else {
                    tmp[1] = num[p];
                    tmp[2] = num[q];
                    res.push_back(tmp);
                    p++, q--;
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
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int sn = sizeof(nums) / sizeof(int);

    vector<int> S(nums, nums+sn);
    vector<vector<int> > res;

    Solution s;
    res = s.threeSum(S);
    print(res);
	system("pause");
	return 0;
}

