#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        string commstr = strs[0];
        for (int i=1; i<strs.size(); i++) {
            string& s = strs[i]; 
            int k = 0;
            while (k<s.size() && k<commstr.size() && s[k] == commstr[k]) k++;
            commstr = commstr.substr(0, k);
            if (k == 0) break;
        }
        return commstr;
    }
};

int main() {
	// NO IMPLEMENTATION
	system("pause");
	return 0;
}

