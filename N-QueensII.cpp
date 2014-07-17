#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
private:
    int queen_num;
    int total;
public:
    int totalNQueens(int n) {
        queen_num = n;
        total = 0;

        vector<bool> h(n, false);
        vector<bool> v(n, false);
        vector<bool> lx(n * 2 + 1, false);
        vector<bool> rx(n * 2 + 1, false);

        dfs(0, h, v, lx, rx);

        return total;
    }

    void dfs(int level, vector<bool> &h, vector<bool> &v, vector<bool> &lx, vector<bool> &rx) {
        if (level == queen_num) {
            total++;
            return;
        }
        int row = level;
        int col = 0;
        while (col < queen_num) {
            if (!h[row] && !v[col] && !lx[row + col] && !rx[row + queen_num - col - 1]) {
                h[row] = v[col] = lx[row + col] = rx[row + queen_num - col - 1] = true;
                dfs(level + 1, h, v, lx, rx);
                h[row] = v[col] = lx[row + col] = rx[row + queen_num - col - 1] = false;
            }
            col++;
        }
    }
};

int main() {
    Solution s;
    cout<<s.totalNQueens(5)<<endl;
	system("pause");
	return 0;
}

