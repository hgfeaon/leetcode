#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
    	string res;
		int carry = 0, s = 0;
		int apos = a.length() - 1;
		int bpos = b.length() - 1;
		int astp = 0, bstp = 0;
		// skip leading zero(s)
		for (; astp < apos && a[astp] == '0'; astp++);
		for (; bstp < bpos && b[bstp] == '0'; bstp++);
		// a/b pos validation
		bool apv = apos >= astp, bpv = bpos >= bstp;
		// addition
		while(apv || bpv) {
			if (apv) s += a[apos] - '0';
			if (bpv) s += b[bpos] - '0';
			carry = s > 1;
			s = s & 0x1;
			res.push_back(s ? '1' : '0');
			apos--, bpos--, s = carry;
			apv = apos >= astp, bpv = bpos >= bstp;
		}
		if (carry) res.push_back('1');
		if (res.empty()) {
			res.push_back('0');
		} else {
			reverse(res.begin(), res.end());
		}
		return res;
    }
};

int main() {
	Solution s;
	
	cout<<s.addBinary("00000000000001100", "100000")<<endl;
	cout<<s.addBinary("", "")<<endl;
	cout<<s.addBinary("", "1")<<endl;
	cout<<s.addBinary("01", "1")<<endl;
	system("pause");
	return 0;
}


