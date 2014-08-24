#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        int len = s.length();
        if (len < 2 || nRows == 1 || len < nRows) return s;
        vector<string> cols;

        int si = 0;
        int ri = 0;
        
        while (si < len) {
            bool inacol = cols.size() % (nRows-1) == 0;
            
            if (!inacol) {
                for (int i=0; i<nRows - 2 && si <len; i++, si++) {
                    cols.push_back(s.substr(si, 1));      // a char as a single column
                }
                continue;
            }
            
            cols.push_back(string());

            for (int i=0; i<nRows && si<len; i++, si++) {
                cols.back().push_back(s[si]);   // all char in a column
            }
        }

        string res;
        int nCols = cols.size();

        int stepa = nRows - 1;
        int stepb = 0;
        
        for (int i=0; i<nRows; i++) {
            bool usea = false;
            int last = -1;
            for (int j = 0; j < nCols; j += usea ? stepa : stepb) {
                usea = !usea;
                if (j == last) continue;
                last = j;
                
                int r = i, c = j;
                
                if (cols[c].length() < 1) break;
                
                if (c % (nRows - 1) != 0) {
                    r = 0;
                } else if (cols[c].length() - 1 < r) {
                    break;
                }
                res.push_back(cols[c][r]);
            }
            --stepa, ++stepb;
        }
        cols.clear();
        return res;
    }
};

int main() {
    Solution s;
    string str = s.convert("ABCDEFGH", 4);

    cout<<str<<endl;
    
    string a("abc");
    string b(a);
    b.push_back(a[10]);
    
    cout<<a<<","<<b<<endl;
    cout<<(a == b)<<endl;
	system("pause");
	return 0;
}

