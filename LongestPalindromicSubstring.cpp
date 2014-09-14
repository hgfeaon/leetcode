#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;


class Solution {
private:
    const char sep_char     = '\1';
public:
    string longestPalindrome(string s) {
        int max_len = 0;
        int len = s.length();
        if (len <= 1) return s;
        
        string str;
        str.push_back(sep_char);
        for (int i=0; i<len; i++) {
            str.push_back(s[i]);
            str.push_back(sep_char);
        }
        cout<<str<<endl;
        int nlen = 2 * len + 1;
        vector<int> P(nlen, 0);
        
        int last_i = 0;
        int last_r = 0;
        
        int maxv = -1;
        int maxi = -1;

        for (int i=0; i<nlen; i++) {
            int p = i, q = i;
            if (i < last_r) {
                int j = 2 * last_i - i;     // (i + j) / 2 = last_i
                int slen = min(P[j], last_r - i);
                p-= slen;
                q+= slen;
            }
            
            while(p >= 0 && q < nlen && str[p] == str[q]) p--, q++;
            if (q > last_r) {
                last_r = q;
                last_i = i;
            }

            P[i] = q - i;
            
            if (P[i] > maxv) {
                maxv = P[i];
                maxi = i;
            }
        }
        return s.substr((maxi + 1 - P[maxi]) / 2, P[maxi] - 1);
    }
};

int main() {
    string str("missing");
    Solution s;
    cout<<s.longestPalindrome(str)<<endl;

	system("pause");
	return 0;
}

