#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void print_strings(vector<string>& v);

void print_ints(vector<vector<int> >& dp);

class Solution {
private:
    vector<string> result;
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<vector<int> > dp;
        result.clear();
        
        int len = s.length();
        dp.resize(len + 1);
        dp[0].push_back(-1);
        
        for (int i=1; i<=len; i++) {
            for (int j=i-1; j>=0; j--) {
                string str = s.substr(j, i - j);
                if (dict.find(str) != dict.end()) {
                    if (dp[j].empty()) continue;
                    dp[i].push_back(j);
                }
            }
        }
        print_ints(dp);
        dfs_build(dp, s, len, "");
        return result;
    }
    
    void dfs_build(vector<vector<int> >& dp, string& s, int len, string sent) {
        vector<int> indices = dp[len];
        for (int i=0; i<indices.size(); i++) {
            int prefix_len = indices[i];
            if (prefix_len <= 0) {
                result.push_back(s.substr(0, len) + sent);
            } else {
                string suffix = s.substr(prefix_len, len - prefix_len);
                dfs_build(dp, s, prefix_len, " " + suffix + sent);
            }
        }
    }
};

void print_strings(vector<string>& v) {
    for (int i=0; i<v.size(); i++) {
        cout<<v[i]<<endl;
    }
}

void print_ints(vector<vector<int> >& dp) {
    for (int i=0; i<dp.size(); i++) {
        for (int j=0; j<dp[i].size(); j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {

    Solution s;
    
    unordered_set<string> dict;
    const char* words[] = {"cat", "cats", "sand", "and", "dog"};
    for (int i=0; i<sizeof(words)/sizeof(const char*); i++) {
        dict.insert(words[i]);
    }
    
    vector<string> ret = s.wordBreak("catsanddog", dict);
    print_strings(ret);
    
	system("pause");
	return 0;
}

