#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack;
        int maxlen = 0;
        int curlen = 0;
        int last = -1;
        int len = s.length();
        for (int i=0; i<len; i++) {
            char ch = s[i];
            if (ch == '(') {
                stack.push_back(i);
                continue;
            }
            if (stack.empty()) {
                last = i;
                continue;
            }
            stack.pop_back();
            if (stack.empty()) {
                curlen = i - last;
            } else {
                curlen = i - stack.back();
            }
            
            if (curlen > maxlen) maxlen = curlen;
        }
        
        return maxlen;
    }
};

int main() {
    Solution s;
    cout<<s.longestValidParentheses("()()")<<endl;
	system("pause");
	return 0;
}

