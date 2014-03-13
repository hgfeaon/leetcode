#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
private:
    // only used by _isValidSudoku
    int row[9];
    int col[9];
    int blk[9];
public:
    bool _isValidSudoku(vector<vector<char> >& board) {
        if (board.empty()) return true;
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(blk, 0, sizeof(blk));
        int rm, cm, bm;
        for (int i=0; i<9; i++) {
            int base = i / 3 * 3;
            for (int j=0; j<9; j++) {
                char ch = board[i][j];
                if (ch == '.') continue;
                int msk = 0x1<<(ch - '0');
                int blk_idx = base + j / 3;
                rm = msk|row[i];
                cm = msk|col[j];
                bm = msk|blk[blk_idx];
                if (rm == row[i] || cm == col[j] || bm == blk[blk_idx]) {
                    return false;
                }
                row[i] = rm;
                col[j] = cm;
                blk[blk_idx] = bm;
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char> >& board) {
        if (board.empty()) return true;
        int mx = board.size() - 1;
        int my = board[0].size() - 1;
        // each row
        for (int i=0; i <= my; i++) {
            if (!isValidRegion(board, 0, i, mx, 0)) return false;
        }
        // each column
        for (int i=0; i <= mx; i++) {
            if (!isValidRegion(board, i, 0, 0, my)) return false;
        }
        // each block
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++){
                if (!isValidRegion(board, j*3, i*3, 2, 2)) return false;   
            }
        }
        return true;
    }
    bool isValidRegion(vector<vector<char> >& board, int sx, int sy, int dx, int dy) {
        char count[10];
        for (int i=0; i<10; i++) count[i] = 0;
        
        for (int i=sy + dy; i >= sy; i--) {
            for (int j=sx + dx; j >= sx; j--) {
                char num = board[i][j];
                if (num == '.') continue;
                if (num > '9' || num < '0') return false;
                if (++count[num-'0'] > 1) return false;
            }    
        }
        return true;
    }
};

void print(vector<vector<char> > &board) {
    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[i].size(); j++)
            cout<<board[i][j];
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    char* sudoku[] = {  ".87654321", 
                        "2........",
                        "3........",
                        "4........",
                        "5........",
                        "6........",
                        "7........",
                        "8........",
                        "9........"};
    vector<vector<char> > board;
    for (int i=0; i<9; i++) board.push_back(vector<char>(sudoku[i], sudoku[i] + strlen(sudoku[i])));
    print(board);
    Solution s;
    cout<<s._isValidSudoku(board)<<endl;
    return 0;
}
