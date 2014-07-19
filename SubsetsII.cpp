#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        int len = S.size();
        vector<vector<int> > res;
        vector<int> subset;
        if (len < 1) {
            res.push_back(subset);
            return res;
        }
        sort(S.begin(), S.end());
        vector<int> stat;
        vector<int> nums;

        int count = 1;
        int cur = S[0];
        int last = cur;
        for (int i=1; i<len; i++) {
            cur = S[i];
            if (cur != last) {
                stat.push_back(count);
                nums.push_back(last);
                last = cur;
                count = 0;
            }
            count++;
        }
        stat.push_back(count);
        nums.push_back(last);

        dfs(nums, stat, res, subset, 0);
    }

    void dfs(vector<int> &nums, vector<int> &stat, vector<vector<int> > &res, vector<int> &subset, int k) {
        if (k >= nums.size()) {
            res.push_back(subset);
            return;
        }

        int cnt = stat[k];

        int old = subset.size();

        for (int i=0; i <= cnt; i++) {
            dfs(nums, stat, res, subset, k + 1);
            subset.push_back(nums[k]);
        }
        subset.resize(old);
    }
};

void print(vector<vector<int> > &list) {
    for (int i=0; i<list.size(); i++) {
        if (list[i].size() == 0) cout<<"Empty set";
        for (int j=0; j<list[i].size(); j++) {
            cout<<list[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    int nums[] = {1, 2, 2};
    vector<int> S(nums, nums + sizeof(nums) / sizeof(int));
    Solution s;
    vector<vector<int> > res = s.subsetsWithDup(S);

    print(res);

    system("pause");
	return 0;
}

