#include <iostream>
#include <cstdlib>

class Solution {
public:
    int atoi(const char *str) {
    	if (str == NULL) return 0;
		long val =0, pos = 0;
        char ch = '\0';
        int stage = 0; // 0-initial, 1-sign-collected, 2-digit-collected, 3-end
		bool positive = true;
		int pos_threshold = INT_MAX / 10;
		int neg_threshold = INT_MIN / 10;
    	while(stage < 3 && (ch = str[pos]) != '\0') {
			switch(stage) {
				case 0: // initial stage
					if (ch == '-' || ch == '+') {
						// sign detected
						positive = ch == '+';
						stage = 1;
						pos++;
					} else if (ch >= '0' && ch <= '9') {
						// digit detected
						stage = 2;
					} else if (ch == ' ' || ch == '\t' || ch == '\n') {
						// leading white space
						pos++;
					} else {
						// other chars, invalid str to convert
						stage = 3;
					}
					;break;
				case 1: // sign-collected stage
					if (ch >= '0' && ch <= '9') {
						// digit after sign
						stage = 2;
					} else {
						// other chars, invalid str to convert
						stage = 3;
					}
					;break;
				case 2: // number detected stage
					if (ch >= '0' && ch <= '9') {
						// digits
						int pre_val = val;
						if (positive) {
							val = val * 10 + (ch - '0');
							if (pre_val > pos_threshold || val < pre_val) {
								stage = 3;
								val = INT_MAX;
							}
						} else {
							val = val * 10 - (ch - '0');
							if (pre_val < neg_threshold || val > pre_val) {
								stage = 3;
								val = INT_MIN;
							}
						}
						pos++;
					} else {
						// other chars, invalid
						stage = 3;
					}
					;break;
			}
		}
    	return val;
    }
};

int main() {
    Solution s;
    std::cout<<s.atoi("123")<<std::endl;
	system("pause");
	return 0;
}

