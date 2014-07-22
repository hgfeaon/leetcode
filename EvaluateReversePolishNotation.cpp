#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int len = tokens.size();
        if (len < 1) return 0;
        
        vector<int> stack;
        for (int i=0; i<len; i++) {
            string &p = tokens[i];
            if (p[0] >= '0' && p[0] <= '9' || p[0] == '-' && p.size() > 1) {
                stack.push_back(stoi(p));
            } else {
                int slen = stack.size();
                stack[slen - 2] = op(p[0], stack[slen - 2], stack[slen - 1]);
                stack.pop_back();
            }
        }

        return stack[0];
    }
    
    int op(const char op, int a, int b) {
        int res = 0;
        switch(op) {
            case '+': res = a + b; break;
            case '-': res = a - b; break;
            case '/': res = a / b; break;
            case '*': res = a * b; break;
        }
        return res;
    }
    
    int stoi(string &s) {
        int len = s.size();
        if (len < 1) return 0;
        bool neg = s[0] == '-';
        int i = neg ? 1 : 0;
        int res = 0;
        while (i < len) {
            res = res * 10 + s[i] - '0';
            i++;
        }
        return neg ? -res : res;
    }
};

int main() {
    const char* exp1[] = {"2", "1", "+", "3", "*"};
    int len1 = sizeof(exp1) / sizeof(char*);
    
    const char* exp2[] = {"4", "13", "5", "/", "+"};
    int len2 = sizeof(exp2) / sizeof(char*);
    
    vector<string> rpn_tokens(exp2, exp2 + len2);

    Solution s;
    
    cout<<s.evalRPN(rpn_tokens)<<endl;

	system("pause");
	return 0;
}

