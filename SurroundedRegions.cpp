#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

void print(vector<vector<char> > &board) {
    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[i].size(); j++)
            cout<<board[i][j]<<", ";
        cout<<endl;
    }
    cout<<endl;
}

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        if (board.size() == 0) return;
        int my = board.size() - 1;
        int mx = board[0].size() -1;
        // top border
        for (int i=0; i<=mx; i++) {
            bfs(board, mx, my, i, 0, 'O', '+');
        }
        // bottom border
        for (int i=0; i<=mx; i++) {
            bfs(board, mx, my, i, my, 'O', '+');
        }
        // left border
        for (int i=0; i<=my; i++) {
            bfs(board, mx, my, 0, i, 'O', '+');
        }
        // right border
        for (int i=0; i<=my; i++) {
            bfs(board, mx, my, mx, i, 'O', '+');
        }
        
        // scan & fill
        for (int i=1; i<=my-1; i++) {
            for (int j=1; j<=mx-1; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        
        // restore
        for (int i=0; i<=my; i++) {
            for (int j=0; j<=mx; j++) {
                if (board[i][j] == '+') board[i][j] = 'O';
            }
        }
    }
    
    void bfs(vector<vector<char> >& board, int mx, int my, int _x, int _y, char oc, char nc) {
        queue<pair<int, int> > que;
        que.push(pair<int, int>(_x, _y));
        
        while (!que.empty()) {
            pair<int, int> blk = que.front();
            que.pop();
            int x = blk.first;
            int y = blk.second;
            if (y <= my && x <= mx && board[y][x] == oc) {
                board[y][x] = nc;
                if (x+1 <= mx && board[y][x+1] == oc) que.push(pair<int, int>(x+1, y));
                if (x-1 >= 0 && board[y][x-1] == oc) que.push(pair<int, int>(x-1, y));
                if (y+1 <= my && board[y+1][x] == oc) que.push(pair<int, int>(x, y+1));
                if (y-1 >= 0 && board[y-1][x] == oc) que.push(pair<int, int>(x, y-1));
            }
        }
    }
};

int main() {
    Solution s;
    
    char rows[] = { 'X', 'O', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'O',
    
                    'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
    
                    'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X',
    
                    'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O',
    
                    'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'O', 'X',
    
                    'X', 'X', 'O', 'X', 'X', 'O', 'O', 'X', 'X', 'X',
    
                    'O', 'X', 'X', 'O', 'O', 'X', 'O', 'X', 'X', 'O',
    
                    'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X',
    
                    'X', 'O', 'O', 'X', 'X', 'O', 'X', 'X', 'O', 'O',
    
                    'X', 'X', 'X', 'O', 'O', 'X', 'O', 'X', 'X', 'O'};

    vector<vector<char> > board;
    
    for (int i=0; i<10; i++) {
        board.push_back(vector<char>(rows + i*10, rows + i*10 + 10));
    }
        
    print(board);
    
    cout<<endl<<endl;
    
    s.solve(board);
    
    print(board);
    
    system("pause");
    return 0;
}
