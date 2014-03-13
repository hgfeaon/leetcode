#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
private:
    int row[9];
    int col[9];
    int blk[9];
    
public:
    void solveSudoku(vector<vector<char> > &board) {
        if (board.empty() || board[0].empty()) return;
        
        initBits(board);
        
        dfs(board, 0, 0);
    }
    
    bool dfs(vector<vector<char> >& board, int ridx, int cidx) {
        if (ridx == 9) {
            return true; // a valid solution will reach it 
        }
        char ch = board[ridx][cidx];
        bool nr = cidx == 8;
        int blk_id = ridx/3*3 + cidx/3;
        
        if (ch != '.') {
            return dfs(board, ridx + nr, nr ? 0 : (cidx+1));
        }
        
        for (int k=1; k<=9; k++) {
            int msk = 0x1<<(k-1);
            if ((msk|row[ridx]) == row[ridx] 
                    || (msk|col[cidx]) == col[cidx] 
                    || (msk|blk[blk_id]) == blk[blk_id]) {
                // this means that in a column or row or block (where current (ridx, cidx) fall)
                // the current number has already been used, so give up this try
                continue;
            }
            setBits(ridx, cidx, blk_id, msk);
            board[ridx][cidx] = k + '0';
            if (dfs(board, ridx + nr, nr ? 0 : (cidx+1))) return true;
            board[ridx][cidx] = ch;
            unsetBits(ridx, cidx, blk_id, msk);
        }
        return false;
    }
    
    void setBits(int r, int c, int b, int msk) {
        row[r] |= msk;
        col[c] |= msk;
        blk[b] |= msk;
    }
    void unsetBits(int r, int c, int b, int msk) {
        row[r] &= ~msk;
        col[c] &= ~msk;
        blk[b] &= ~msk;
    }
    
    void initBits(vector<vector<char> > &board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(blk, 0, sizeof(blk));
        
        int rm, cm, bm;
        for (int i=0; i<9; i++) {
            int base = i / 3 * 3;
            for (int j=0; j<9; j++) {
                char ch = board[i][j];
                if (ch == '.') continue;
                int msk = 0x1<<(ch - '0' - 1);
                int blk_idx = base + j / 3;
                setBits(i, j, blk_idx, msk);
            }
        }
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
    Solution s;
    char* sudoku[] = {  "..9748...",
                        "7........",
                        ".2.1.9...",
                        "..7...24.",
                        ".64.1.59.",
                        ".98...3..",
                        "...8.3.2.",
                        "........6",
                        "...2759.."};
    vector<vector<char> > board;
    
    for (int i=0; i<9; i++) board.push_back(vector<char>(sudoku[i], sudoku[i] + strlen(sudoku[i])));
    
    s.solveSudoku(board);
    
    print(board);
    
    system("pause");
    return 0;
}

