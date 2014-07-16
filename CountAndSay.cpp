#include <iostream>
#include <cstdlib>

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector<int> num;
        num2digit(1, num);

        vector<int> tmp;
        for (int i = 1; i<n; i++) {
            int last = num[0];
            int cur  = last;
            int count= 1;

            for (int i=1; i < num.size(); i++) {
                cur = num[i];
                if (cur != last) {
                    num2digit(count, tmp);
                    tmp.push_back(last);
                    last = cur;
                    count = 1;
                } else {
                    count++;
                }
            }
            
            num2digit(count, tmp);
            tmp.push_back(cur);

            swap(num, tmp);
            tmp.clear();
        }
        string res;
        for (int i=0; i<num.size(); i++) {
            res.push_back((char)(num[i] + '0'));
        }
        return res;
    }

    void num2digit(int n, vector<int> &digits) {
        vector<int> res;
        if (n < 0) {
            n = -n;
        }

        do {
            res.push_back(n % 10);
            n /= 10;
        } while (n != 0);

        for (int i=res.size() - 1; i >= 0; i--) {
            digits.push_back(res[i]);
        }
    }
};

int main() {
    Solution s;
    
    string res = s.countAndSay(3);
    
    cout<<res<<endl;
	system("pause");
	return 0;
}

