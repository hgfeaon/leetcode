#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int pow = 1;
        int t = x;
        int cnt = 1;
        while(t /= 10) {
            pow *= 10;
            cnt++;
        }
        t = x;
        cnt = cnt / 2;
        while (cnt--) {
            //cout<<t<<endl;
            if ((t / pow % 10) != t % 10) return false;
            t = t / 10;
            pow /= 100;
        }
        return true;
    }

};

int main() {
    Solution s;
    cout<<s.isPalindrome(998799)<<endl;
	system("pause");
	return 0;
}

