#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) return 1;
        unsigned int k = 0;
        if (n < 0) {
            x = 1.0 / x;
            k = -n;
        } else {
            k = n;
        }
        if (k == 1) return x;
        
        double r = pow(x, k/2);
        r = r * r;
        if (0x1 & k) {
            r = r * x;
        }
        return r;
    }
    
    double _pow(double x, int n) {
        unsigned int k = 0;
        if (n < 0) {
            k = -n;
            x = 1.0 / x;
        } else {
            k = n;
        }
        double ret = 1;
        while (k != 0) {
            if (k & 0x1) ret *= x;
            x *= x; 
            k>>=1;
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout<<s.pow(2, 5)<<endl;
    return 0;
}
