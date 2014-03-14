#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

class Solution {
private:
    // used by dfs only
    int* memo;
    const char* str;
public:
    // 1 .dfs using a memo
    int _numDecodings(string s) {
        str = s.c_str();
        memo = new int[s.length()];
        memset(memo, -1, sizeof(int) * s.length());
        
        int ways = dfs(str, str + s.length() - 1);
        
        delete[] memo;
        return ways;
    }
    
    // 2. dynamic programming
    int numDecodings(string s) {
        const char* str = s.c_str();
        int len = s.length();
        if (len == 0) return 0;
        int ways = 0;
        
        int (*dp)[2] = new int[len + 2][2];
        dp[0][0] = dp[0][1] = dp[1][1] = 0;
        dp[1][0] = 1;
        
        for (int i=0; i<len; i++) {
            int d1 = str[i] - '0', d2 = 0;
            int prev = dp[i+1][0] + dp[i][1];
            bool d1_valid = (d1>=1 && d1<=26);
            dp[i+2][0] = d1_valid ? prev : 0;
            
            if (i+1 < len && d1_valid) {
                d2 = d1 * 10 + str[i+1] - '0';
                dp[i+2][1] = (d2 >=1 && d2 <= 26) ? prev : 0;
            } else {
                dp[i+2][1] = 0;
            }
        }
        ways = dp[len - 1 + 2][0] + dp[len - 2 + 2][1];
        delete[] dp;
        return ways;
    }
    
    int dfs(const char* cur, const char* last) {
        if (cur > last) return 0;
        int d1 = *cur - '0';
        if (d1 < 1 || d1 > 26) return 0;
        int midx = cur - str;
        if (memo[midx] != -1) return memo[midx];
        
        
        int d2 = 0;
        
        if (cur != last) {
            d2 = d1*10 + *(cur+1)-'0';
        }
        int c1 = 0, c2 = 0;
        if (cur == last) {       // last one digit
            c1 = 1;
        } else {                        // other cases
            c1 = dfs(cur + 1, last);
        }
        if (d2 > 26) {                  // invalid
            c2 = 0;
        } else if (cur + 1 ==  last) {  // last two digit
            c2 = 1;
        } else {                        // other cases
            c2 = dfs(cur + 2, last);
        }
        
        memo[midx] = c1 + c2;
        return memo[midx];
    }
};

int main() {
    Solution s;
    cout<<s.numDecodings("01")<<endl;
    return 0;
}
