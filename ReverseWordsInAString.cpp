#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
    	int len = s.length();
		reverse(s.begin(), s.end());
		int wpos = 0;
		for (int p=0, q=0; p < len; p = q) {
			while ((p<len) && (s[p] == ' ')) p++;
			q = p;
			while ((q<len) && (s[q] != ' ')) q++;
			reverse(s.begin() + p, s.begin() + q);
			if (wpos != 0 && p < q) s[wpos++] = ' ';
			for (int i=p; i<q; i++) {
				s[wpos++] = s[i];
			}
    	}
    	if (wpos != len) s = s.substr(0, wpos);
    }
};

int main() {
	Solution s;
	string str("  hello    world   ");
	s.reverseWords(str);
	cout<<str<<"=";
	system("pause");
	return 0;
}

