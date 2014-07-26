#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
    	if (s == NULL || p == NULL) return false;
        int slen = 0;
        int plen = 0;
        
        while (s[slen] != '\0') slen++;
        while (p[plen] != '\0') plen++;
        
        if (slen == 0 && plen == 0) return true;
        if (plen == 0) return false;
        
        int si = 0;
        int pi = 0;
        int ppi = -1;
        int psi = 0;
        
        while (si < slen) {
            if (s[si] == p[pi] || p[pi] == '?') {
                si++, pi++;
            } else if (p[pi] == '*') {
                ppi = pi++;
                psi = si;
            } else if (ppi != -1){
                pi = ppi + 1;
                si = ++psi;
            } else {
                return false;
            }
        }

        while (p[pi] == '*') pi++;
        return pi == plen;
    }
};

int main() {
	Solution s;
	cout<<s.isMatch("", "*a*")<<endl;
	system("pause");
	return 0;
}

