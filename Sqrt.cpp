#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int _sqrt(int x) {
        int i = 0;
        int m = 0;
        while (i <= x) {
            m = i * i;
            if (m == x) {
                break;
            } else if (m > x) {
                i--;
                break;
            } else {
                i++;
            }
        }
        return i;
    }
    
    int sqrt(int x) {
        int lo = 0;
        int hi = x;
        int m = 0;
        double mul = 0;
        for (;;) {
            times++;
            m = (lo + hi) / 2;
            if (lo > hi) break;
            mul = 1.0 * m * m;
            if (mul > x) {
                hi = m - 1;
            } else if (mul == x) {
                break;
            } else {
                lo = m + 1;
            }
        }
        return m;
    }
    
    int nsqrt(int x) {
        if (x == 0) return 0;
        double i = x;
        int last;
        for(;;) {
            last = i;
            i = i - i/2.0 + x/2.0/i;
            if ((int)i == last) break;
        }
        return last;
    }
};
int main() {
    Solution s;
    cout<<s.sqrt(2147395599)<<endl;
    return 0;
}
