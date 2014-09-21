#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    // a valid number should be in the below form
    // -/+digit.digitE/e+/-digit
    bool isNumber(const char *s) {
        if (s == NULL) return false;
        int end = 0;
        while (s[end] != '\0') end++;
        while (s[--end] == ' ');
        end++;
        // 0-initial, 1-sign-collected, 2-integer_part digit collected, 3-float_point collected,
        // 4-fraction part digit collected, 5-e/E collected, 6-sign of E collected, 7-digit of E collected,
        // 8-mid_space
        int stage = 0; 
        int pos = 0;
        char ch = '\0';
        
        int stages = 0;;

        while ((ch = s[pos]) != '\0' && pos < end) {
            switch(stage) {
                case 0: // initial
                    if (ch == ' ') {
                        // white spaces, just skip
                        pos++;
                    } else if (ch == '+' || ch == '-') {
                        // sign found
                        stage = 1;
                        pos++;
                    } else if (ch == '.') {
                        // float point found
                        stage = 3;
                        pos++;
                    } else if (ch >= '0' && ch <= '9') {
                        // digit found
                        stage = 2;
                    } else {
                        // the other chars are invalid in [initial stage]
                        return false;
                    }
                    break;
                case 1: // sign collected
                    stages |= 1<<(stage - 1);
                    if (ch >= '0' && ch <= '9') {
                        // digit found
                        stage = 2;
                    } else if (ch == '.') {
                        // float point found
                        stage = 3;
                        pos++;
                    } else {
                        // the other chars are invalid in [sign collected stage]
                        return false;
                    }
                    break;
                case 2: // integer part digit collected
                    stages |= 1<<(stage - 1);
                    if (ch >= '0' && ch <= '9') {
                        // integer part digit found
                        pos++;
                    } else if (ch == '.'){
                        // float point found
                        pos++;
                        stage = 3;
                    } else if (ch == 'e' || ch == 'E') {
                        // E found
                        pos++;
                        stage = 5;
                    } else {
                        // the other chars are invalid
                        return false;
                    }
                    break;
                case 3: // float point collected
                    stages |= 1<<(stage - 1);
                    if (ch >= '0' && ch <= '9') {
                        // fraction part digit found
                        stage = 4;
                    } else if (ch == 'E' || ch == 'e') {
                        // E/e found
                        pos++;
                        stage = 5;
                    } else {
                        // the other chars are invalid
                        return false;
                    }
                    break;
                case 4: // fraction part digit collected
                    stages |= 1<<(stage - 1);
                    if (ch >= '0' && ch <= '9') {
                        // fraction part digit found
                        pos++;
                    } else if (ch == 'e' || ch == 'E') {
                        // e/E found;
                        pos++;
                        stage = 5;
                    } else {
                        return false;
                    }
                    break;
                case 5: // e/E collected
                    stages |= 1<<(stage - 1);
                    if (ch >= '0' && ch <= '9') {
                        // E digit found
                        stage = 7;
                    } else if (ch == '-' || ch == '+') {
                        // sign of e found
                        pos++;
                        stage = 6;
                    } else {
                        return false;
                    }
                    break;
                case 6: // sign of E collected
                    stages |= 1<<(stage - 1);
                    if (ch >= '0' && ch <= '9') {
                        // E digit found
                        stage = 7;
                    } else {
                        // others are invalid
                        return false;
                    }
                    break;
                case 7: // digit of E collected
                    stages |= 1<<(stage - 1);
                    if (ch >= '0' && ch <= '9') {
                        pos++;
                    } else {
                        return false;
                    }
                    break;
                default:
                    cout<<"case should not happen"<<endl;
                    return false;
            }
        }
        
        // should not end with these stage
        if (stage == 0 || stage == 1 || stage == 5 || stage == 6) {
            return false;
        }
        // float point collected and no preceed integer found
        // (hasn't walk through integer part stage)
        if (stage == 3 && !(stages & 1<<1)) {
            return false;
        }
        
        // E collected but no base number collected
        // (hasn't walk through neither integer part digit stage or fraction part digit stage)
        if ((stages & 1<<4) && !(stages & 1<<1) && !(stages & 1<<3)) {
            return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout<<s.isNumber(".e1")<<endl;
	system("pause");
	return 0;
}

