#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <cmath>
#include <cstring>


using namespace std;

class Solution {
private:
    int cols;
    int rows;
    int len;
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (word.size() == 0) return true;
        rows = board.size();
        if (rows == 0) return false;
        cols = board[0].size();
        len  = word.length();
        char first = word[0];
        for (int i=0; i<rows; i++) {
            vector<char>& row = board[i];
            for (int j=0; j<cols; j++) {
                if (row[j] == first && dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char> >& board, string& word, int pos, int i, int j) {
        char ch = word[pos];
        if (pos == len - 1) return true;
        char next = word[pos + 1];
        bool ret;
        if (j + 1 < cols && board[i][j + 1] == next) {
            board[i][j] = 0;
            ret = dfs(board, word, pos + 1, i, j + 1);
            board[i][j] = ch;
            if (ret) return true;
        }
        if (j - 1 >= 0 && board[i][j - 1] == next) {
            board[i][j] = 0;
            ret = dfs(board, word, pos + 1, i, j - 1);
            board[i][j] = ch;
            if (ret) return true;
        }
        if (i + 1 < rows && board[i+1][j] == next) {
            board[i][j] = 0;
            ret = dfs(board, word, pos + 1, i + 1, j);
            board[i][j] = ch;
            if (ret) return true;
        }

        if (i - 1 >= 0 && board[i-1][j] == next) {
            board[i][j] = 0;
            ret = dfs(board, word, pos + 1, i - 1, j);
            board[i][j] = ch;
            if (ret) return true;
        }
        return false;
    }
};

int main() {
    char* chartable[] = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaab"};
    vector<vector<char> > board;
    for (int i=0; i<sizeof(chartable)/sizeof(char*); i++) {
        char* row = chartable[i];
        board.push_back(vector<char>(row, row + strlen(row)));
    }
    string word("baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    
    Solution s;
   
    cout<<s.exist(board, word)<<endl;

    system("pause");
    return 0;
}

