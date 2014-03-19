#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

class Solution {
private:
    // only used by dfs
    int *memo;
    int cols;
public:
    // 1. dfs
    int numDistinct(string S, string T) {
        int ret = 0;
        cols = T.length();
        int msize = S.length() * cols;
        memo = new int[msize];
        memset(memo, -1, msize * sizeof(int));
        ret = dfs(S, 0, T, 0);
        delete[] memo;
        return ret;
    }
    
    int dfs(string& S, int pa, string& T, int pb) {
        
        if (pb >= T.size()) {
            return 1;
        }
        if (pa >= S.size()) return 0;
        if (memo[pa * cols + pb] != -1) return memo[pa * cols + pb];
        int r = 0;
        if (S[pa] == T[pb]) {
            r += dfs(S, pa + 1, T, pb + 1);
        }
        r += dfs(S, pa + 1, T, pb);
        memo[pa * cols + pb] = r;
        return r;
    }
    
    // 2. dynamic programming
    int _numDistinct(string S, string T) {
        int ret = 0;
        int rows = S.length() + 1;
        int cols = T.length() + 1;
        int* dp = new int[rows * cols];
        
        for (int i=0; i<cols; i++) dp[i] = 0;
        for (int i=0; i<rows; i++) dp[i*cols] = 1;
        
        for (int i=1; i<rows; i++) {
            for (int j=1; j<cols; j++) {
                dp[i*cols + j] = ((S[i-1] == T[j-1]) ? dp[(i-1)*cols + j-1]:0)
                                + dp[(i-1) * cols + j]; 
            }    
        }
        ret = dp[rows * cols - 1];
        delete[] dp;
        return ret;
    }
};

int main() {
    Solution s;
    cout<<s._numDistinct("xrabbbit", "rabbit")<<endl;
    system("pause");
    return 0;    
}
