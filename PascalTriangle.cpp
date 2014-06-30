#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if (numRows < 1) return res;

        vector<int> row(1, 1);
        res.push_back(row);

        for (int i=2; i<=numRows; i++) {
            res.push_back(vector<int>(i, 1));
            vector<int> &crow = res.back();

            int half = i / 2;
            int j = 1;
            for (; j<half; j++) {
                crow[i-j-1] = crow[j] = res[i-2][j] + res[i-2][j-1];
            }
            if (i & 0x1) {
                crow[j] = res[i-2][j] * 2;
            }
        }
        return res;
    }
};

int main() {


    Solution s;
    vector<vector<int> > res = s.generate(3);
    
	system("pause");
	return 0;
}

