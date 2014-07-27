#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct mystat {
    int idx;
    int cnt[26];
    mystat(int id = 0) {idx = id;}
};

bool cmp(const mystat &a, const mystat &b) {
    for (int i=0; i<26; i++) {
        if (a.cnt[i] < b.cnt[i]) {
            return true;
        } else if (a.cnt[i] > b.cnt[i]) {
            break;
        } else {
            continue;
        }
    }
    return false;
}

bool same(const mystat &a, const mystat &b) {
    for (int i=0; i<26; i++) {
        if (a.cnt[i] != b.cnt[i]) return false;
    }
    return true;
}

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        vector<mystat> stats;

        int len = strs.size();

        for (int i=0; i<len; i++) {
            stats.push_back(mystat(i));

            for (int j=strs[i].size() - 1; j>=0; j--) {
                stats.back().cnt[strs[i][j] - 'a']++;
            }
        }
        
        sort(stats.begin(), stats.end(), cmp);

        int si = 0;

        while (si < len ) {
            int i = si + 1;
            for (; i<len; i++) {
                if (same(stats[si], stats[i])) {
                    res.push_back(strs[stats[i].idx]);
                } else {
                    break;
                }
            }
            if (si + 1 < i) {
                res.push_back(strs[stats[si].idx]);
            }
            si = i;
        }
        return res;
    }
    
};



int main() {
    const char* ss[] = {"ute","fey","toe","lob","pet","ted","old","bye","car","peg","maw","toe","has","dot","tam"};
    int len = sizeof (ss) / sizeof (const char*);
    
    vector<string> strs(ss, ss+len);
    
    Solution s;
    
    vector<string> res = s.anagrams(strs);
    
    for (int i=0; i<res.size(); i++) {
        cout<<res[i]<<endl;
    }
    
	system("pause");
	return 0;
}

