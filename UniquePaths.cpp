#include <iostream>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int (*dp)[101] = new int[101][101];
        for (int i=0;i<101;i++) dp[0][i] = 0;
        for (int i=0;i<101;i++) dp[i][0] = 0;
        dp[0][1] = 1;
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                // to reach (i,j), we can move from 
                // 1. (i, j-1), move right 1 block
                // 2. (i-1, j), move down 1 block
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;
    cout<<s.uniquePaths(4, 4)<<endl;
    return 0;
}
