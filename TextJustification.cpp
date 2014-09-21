#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int len = words.size();
        vector<string> res;
        if (L < 1) {
            res.push_back(string(""));
            return res;
        }
        int pos = 0;

        while (pos < len) {
            int pre_pos = pos;
            int llen = words[pos++].size();

            while (pos < len) {
                if (llen + 1 + words[pos].length() > L) {
                    break;
                }
                llen = llen + 1 + words[pos++].length();
            }
            bool last_line = pos >= len;
            
            int wcnt = pos - pre_pos;       // number of words in one line
            int wlen = llen - (wcnt - 1);   // length of words in one line
            int space= L - wlen;            // space in one line

            string line;
            bool left_justify = last_line || wcnt == 1;

            // avg space if space can be distributed evenly, it should be a integer
            // or it will be a float and rounded to a integer
            int avg_space = 0;
            
            // when the avg space has been rounded, ext_space indicates the lost spaces
            int ext_space = 0;
            
            // be sure that zero divide will not happend
            // last line do not need avg_space and ext_space
            if (!left_justify) {
                avg_space = space / (wcnt - 1);
                ext_space = space - avg_space * (wcnt - 1);
            }
            // start to build a line
            line = words[pre_pos];

            for (int i=1; i<wcnt; i++) {
                if (left_justify) {
                    line.push_back(' ');
                } else {
                    line.append(string((ext_space-- > 0 ? 1 : 0) + avg_space, ' '));
                }
                line.append(words[pre_pos + i]);
            }
            if (line.size() < L) {
                line.append(string(L - line.size(), ' '));
            }
            res.push_back(line);
        }
        
        return res;
    }
};


void print(vector<string>& s) {
    for (int i=0; i<s.size(); i++) {
        cout<<s[i]<<"|"<<endl;
    }
}
int main() {
    Solution s;
    const char* w[] = {"Listen","to","many,","speak","to","a","few."};
    vector<string> words(w, w + sizeof(w) / sizeof(const char*));
    words.push_back(string(""));

    vector<string> res = s.fullJustify(words, 6);

    print(res);
	system("pause");
	return 0;
}

