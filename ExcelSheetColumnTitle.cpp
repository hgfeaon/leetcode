#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        if (n <= 0) {
            return "";
        }
        string res;
        while (n>0) {
            n--;
            res = (char)(n % 26 + 'A') + res;
            n /= 26;
        }
        return res;
    }
};

int main() {
    Solution s;

    for (int i=0; i < 1000; i++) {
        cout<<s.convertToTitle(i)<<endl;
    }
    
	system("pause");
	return 0;
}

