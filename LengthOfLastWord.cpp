#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
		if (s == NULL) return 0;
        int mlen = 0, len = 0;
        bool inword = false;
        int pos = 0;
        char ch = 0;
        while ((ch = s[pos]) != '\0') {
            if (ch != ' ') {
                if (!inword) inword = true;
                len++;
            } else if (inword) {
                if (len > 0) mlen = len;
	            len = 0;
	            inword = false;
            }
	            pos++;
        }
        if (len > 0) mlen = len;
        return mlen;
	}
};
int main() {
    const char* str = "   hello world veryverylong  ";
	
	Solution s;
	int len = s.lengthOfLastWord(str);
	cout<<len<<endl;

	return 0;
}
