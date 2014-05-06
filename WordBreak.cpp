#include <iostream>
#include <cstdlib>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
private:
    int* memo;
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        memo = new int[s.length() + 1];

        for (int i=0; i<=s.length(); i++) memo[i] = -1;
        
        bool ret = dfs(s, 0, dict);
        delete[] memo;
        return ret;
    }

    bool dfs(string& s, int pos, unordered_set<string> &dict) {
        if (pos >= s.length()) return true;
        int rest_len = s.length() - pos;
        for (int i = rest_len; i >=1; i--) {
            if (dict.find(s.substr(pos, i)) != dict.end()) {
                if (memo[pos + i] == -1) {
                    memo[pos + i] = dfs(s, pos + i, dict);
                }
                if (memo[pos + i] == 1) return true;
            }
        }
        return false;
    }
    
    bool dynamic_programming(string s, unordered_set<string> &dict) {
        bool* dp = new bool[s.length() + 1];
        for (int i=0; i<=s.length(); i++) dp[i] = false;
        dp[0] = true;
        for (int i=1; i<=s.length(); i++) {
            for (int j=i-1; j>=0; j--) {
                if (dict.find(s.substr(j, i-j)) != dict.end() && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        bool ret = dp[s.length()];
        delete[] dp;
        return ret;
    }
};

int main() {

    unordered_set<string> dict;
    dict.insert("hello");
    dict.insert("boy");
    dict.insert("girl");
    dict.insert("every");
    dict.insert("one");
    Solution s;
    
    cout<<s.dynamic_programming("helloeveryones", dict)<<endl;
    
	system("pause");
	return 0;
}

