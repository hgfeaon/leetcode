#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool aneg = dividend < 0;
        bool bneg = divisor < 0;
        unsigned int a = dividend;
        unsigned int b = divisor;
        if (aneg) a = ~(a - 1);
        if (bneg) b = ~(b - 1);
        unsigned int oa = a, ob = b;
        if (b > a || a == 0) return 0;

        unsigned int abits = 0, bbits = 0;
        while (a) a>>=1, abits++;
        while (b) b>>=1, bbits++;
        a = oa, b = ob;
        unsigned int a_high_bit = 1<<(abits-1);
        unsigned int mask = a_high_bit;
        for (int i=bbits-1; i>0; i--) {
            mask = a_high_bit | (mask>>1);
        }
        unsigned int res = 0;
        unsigned int r_mask = 1<<(abits - bbits);
        b = b<<(abits - bbits);
        while (r_mask) {
            if ((mask & a) >= (mask & b)) {
                res |= r_mask;
                a = a - b;
            }
            mask = (mask>>1)|a_high_bit;
            r_mask>>=1;
            b>>=1;
        }
        if (aneg^bneg)
            return -res;
        else
            return res;
    }
};

int main() {
    Solution s;
    cout<<s.divide(-2147483648, 1)<<endl;
	system("pause");
	return 0;
}

