#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = remove_leading_zero(num1);
        int len2 = remove_leading_zero(num2);

        string muls[10];
        muls[0] = "0";
        for (int i=1; i<10; i++) {
            muls[i] = add(muls[i-1], num1);
        }
        
        string ending_zero(""), res("");
        int pos2 = len2 - 1;
        while (pos2 >= 0) {
            int c = num2[pos2--] - '0';
            res = add(res, muls[c] + ending_zero);
            ending_zero.insert(ending_zero.end(), '0');
        }
        return res;
    }
    
    string add(string num1, string num2) {
        string res("");
        int pos1 = remove_leading_zero(num1) - 1;
        int pos2 = remove_leading_zero(num2) - 1;

        int carry = 0;
        
        while (pos1 >=0 && pos2 >= 0) {
            int c1 = num1[pos1--] - '0';
            int c2 = num2[pos2--] - '0';
            int sum= c1 + c2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            res.insert(res.begin(), sum + '0');
        }
        while (pos1 >=0 ) {
            int c = num1[pos1--] - '0';
            int s = c + carry;
            carry = s / 10;
            s = s % 10;
            res.insert(res.begin(), s + '0');
        }
        while (pos2 >=0 ) {
            int c = num2[pos2--] - '0';
            int s = c + carry;
            carry = s / 10;
            s = s % 10;
            res.insert(res.begin(), s + '0');
        }
        if (carry > 0 ) res.insert(res.begin(), carry + '0');
        return res;
    }
    
    int remove_leading_zero(string& str) {
        int len = str.length();
        int pos = 0;
        
        while(pos < (len - 1) && str[pos] == '0') pos++;
        len = len - pos;
        str = str.substr(pos, len);
        return len;
    }
};

int main() {

    Solution s;
    cout<<s.multiply("0", "789543219")<<endl;
	system("pause");
	return 0;
}

