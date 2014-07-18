#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string str;
        vector<string> res;
        dfs(n, 0, 0, str, res);
        return res;
    }

    void dfs(int n, int L, int R, string str, vector<string> &res) {
        if (str.size() == n<<1) {
            res.push_back(str);
            return;
        }
        int len = str.length();
        for (int i = L + 1; i <= n; i++) {
            dfs(n, i, R, str + "(", res);
        }

        for (int i = R + 1; i <= n && R < L; i++) {
            dfs(n, L, i, str +")", res);
        }
    }
};

int main() {
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    for (int i=0; i<res.size(); i++) {
        cout<<res[i]<<endl;
    }
	system("pause");
	return 0;
}
0
