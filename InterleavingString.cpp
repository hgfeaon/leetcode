#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<unsigned int, bool> memo;
public:
    bool isInterleave(string s1, string s2, string s3) {
        memo.clear();
        return dfs(s1, 0, s2, 0, s3);
    }

    bool isInterleave2(string s1, string s2, string s3) {
        return dp(s1, s2, s3);
    }
    bool dfs(string& s1, int apos, string &s2, int bpos, string &s3) {
        unsigned int id = (apos << 16) | bpos;
        auto iter = memo.find(id);
        if (iter != memo.end()) return iter->second;
        
        int cpos = apos + bpos;
        if (apos == s1.length() && bpos == s2.length() && cpos == s3.length()) {
            memo.insert(make_pair(id, true));
            return true;
        }
        
        bool res = false;
        
        if (apos < s1.length() && s1[apos] == s3[cpos]) {
            if (dfs(s1, apos + 1, s2, bpos, s3)) {
                res = true;
            }
        }
        
        if (!res && bpos < s2.length() && s2[bpos] == s3[cpos]) {
            if (dfs(s1, apos, s2, bpos + 1, s3)) {
                res = true;
            }
        }
        
        memo.insert(make_pair(id, res));
        return res;
    }
    
    bool dp_helper(string &s1, string &s2, string &s3) {
        int rows = s1.length() + 1;
        int cols = s2.length() + 1;
        
        vector<bool> dp(cols, false);
        dp[0] = true;
        
        // init the dp array
        for (int i=1; i<cols; i++) {
            if (s3[i - 1] != s2[i - 1]) break;
            dp[i] = true;
        }
        
        // simplified dp using O( max(len(s1), len(s2)) ) space
        for (int i=1; i<rows; i++) {
            // whether all chars from s1 or not
            dp[0] = dp[0] && (s1[i-1] == s3[i-1]);
            for (int j=1; j<cols; j++) {
                int pos = i + j - 1;
                
                if (dp[j] && s1[i-1] == s3[pos]) {
                    // char from s1, if so, keep dp[j] unchanged( = true)
                } else if (dp[j-1] && s2[j-1] == s3[pos]) {
                    // char from s2
                    dp[j] = true;
                } else {
                    dp[j] = false;
                }
            }
        }
        return dp[cols - 1];
    }
    
    bool dp(string &s1, string &s2, string &s3) {
        int la = s1.length();
        int lb = s2.length();
        if (la + lb != s3.length()) return false;
        if (la < lb) {
            return dp_helper(s1, s2, s3);
        } else {
            return dp_helper(s2, s1, s3);
        }
    }
};

int main() {

	Solution s;
	cout<<s.isInterleave2("aabcc", "dbbca", "aadbbcbcac")<<endl;
	return 0;
}

