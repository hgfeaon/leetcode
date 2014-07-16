#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int queen_num;
    vector<vector<string> > res;
public:
    vector<vector<string> > solveNQueens(int n) {
        res.clear();
        queen_num = n;
        
        vector<bool> h(n, false);
        vector<bool> v(n, false);
        vector<bool> lx(n * 2 + 1, false);
        vector<bool> rx(n * 2 + 1, false);

        vector<int> solution;
        
        dfs(solution, h, v, lx, rx);
        
        return res;
    }

    void dfs(vector<int> &mem, vector<bool> &h, vector<bool> &v, vector<bool> &lx, vector<bool> &rx) {
        if (mem.size() == queen_num) {
            add_solution(mem);
            return;
        }
        int row = mem.size();
        int col = 0;
        while (col < queen_num) {
            if (!h[row] && !v[col] && !lx[row + col] && !rx[row + queen_num - col - 1]) {
                h[row] = v[col] = lx[row + col] = rx[row + queen_num - col - 1] = true;
                mem.push_back(col);
                dfs(mem, h, v, lx, rx);
                mem.pop_back();
                h[row] = v[col] = lx[row + col] = rx[row + queen_num - col - 1] = false;
            }
            col++;
        }
    }

    void add_solution(vector<int> &solution) {
        res.push_back(vector<string>());

        string line(queen_num, '.');
        for (int i=0; i<queen_num; i++) {
            line[solution[i]] = 'Q';
            res.back().push_back(line);
            line[solution[i]] = '.';
        }
    }
};

void print_cheese(vector<string> &board) {
    for (int i=0; i<board.size(); i++) {
        cout<<board[i]<<' '<<endl;
    }
}
int main() {

    Solution s;
    vector<vector<string> > res = s.solveNQueens(5);

    for (int i=0; i<res.size(); i++) {
        print_cheese(res[i]);
        cout<<endl;
    }
    
	system("pause");
	return 0;
}

