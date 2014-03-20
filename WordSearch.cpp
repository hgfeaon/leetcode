#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <cmath>
#include <cstring>
#include <chrono>
#include <ctime>
#include <ratio>

using namespace std;

typedef struct tagCharUsed {
    int i;
    int j;
    bool used;
    tagCharUsed(int _i, int _j, bool _used = false): i(_i), j(_j), used(_used){};
} CharUsed;

class Solution {
public:
    int times;
public:
    bool exist(vector<vector<char> > &board, string word) {
        vector<CharUsed> table[256];
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                table[board[i][j]].push_back(CharUsed(i, j));
            }
        }
        bool ret = dfs(board, table, word, 0, NULL);
        for (int i=1; i<times; i++) {
            cout<<".";
            if (ret != dfs(board, table, word, 0, NULL)) {
                cout<<"Error"<<endl;
                break;
            }
        }
        return ret;
    }
    
    bool dfs(vector<vector<char> >& board, vector<CharUsed>* table, string& word, int pos, CharUsed* last) {
        if (pos >= word.size()) return true;
        char ch = word[pos];
        vector<CharUsed>& chars = table[ch];
        bool ret = false;
        for (int i=0; i<chars.size(); i++) {
            CharUsed& cur = chars[i];
            if (cur.used || (last != NULL && abs(last->i - cur.i) + abs(last->j - cur.j) > 1)) continue;
            cur.used = true;
            ret = dfs(board, table, word, pos + 1, &cur);
            cur.used = false;
            if (ret) return true;
        }
        return false;
    }
};

// 1CE, 1AC, very smooth. CODE FROM ZHULI
class Solution2 {
public:
    int times;
public:
    bool exist(vector<vector<char> > &board, string word) {
        int ret = _exist(board, word);
        for (int i=1; i<times; i++) {
            cout<<".";
            if (ret != _exist(board, word)) {
                cout<<"Error"<<endl;
                break;
            }
        }
        return ret;
    }
    bool _exist(vector<vector<char> > &board, string word) {
        n = (int)board.size();
        if (n == 0) {
            return false;
        }
        m = (int)board[0].size();
        word_len = (int)word.length();

        if (word_len == 0) {
            return true;
        }

        int i, j;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                if(dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    int n, m;
    int word_len;

    bool dfs(vector<vector<char> > &board, string &word, int x, int y, int idx) {
        if (x < 0 || x > n - 1 || y < 0 || y > m - 1) {
            return false;
        }

        if (board[x][y] < 'A' || board[x][y] != word[idx]) {
            // already searched here
            // letter mismatch here
            return false;
        }

        bool res;
        if (idx == word_len - 1) {
            // reach the end of word, success
            return true;
        } else {
            // up
            board[x][y] -= 'A';
            res = dfs(board, word, x - 1, y, idx + 1);
            board[x][y] += 'A';
            if (res) {
                return true;
            }

            // down
            board[x][y] -= 'A';
            res = dfs(board, word, x + 1, y, idx + 1);
            board[x][y] += 'A';
            if (res) {
                return true;
            }

            // left
            board[x][y] -= 'A';
            res = dfs(board, word, x, y - 1, idx + 1);
            board[x][y] += 'A';
            if (res) {
                return true;
            }

            // right
            board[x][y] -= 'A';
            res = dfs(board, word, x, y + 1, idx + 1);
            board[x][y] += 'A';
            if (res) {
                return true;
            }
        }
        // all letters will be within [A-Z], thus I marked a position as 'searched' by setting them to an invalid value.
        // we have to restore the value when the DFS is done, so their values must still be distiguishable.
        // therefore, I used an offset value of 'A'.
        // this tricky way is to save the extra O(n * m) space needed as marker array.
        return false;
    }
};


class Solution3 {
private:
    int move[8];
public:
    bool exist(vector<vector<char> > &board, string word) {
        int m[] = {1, 0, -1, 0, 0, 1, 0, -1};
        for (int i=0; i<8; i++) move[i] = m[i];
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char> >& board, string& word, int pos, int i, int j) {
        if (pos >= word.size()) return true;
        if (i < 0 || j < 0 || i>=board.size() || j>=board[0].size()) return false;
        
        char ch = board[i][j];
        if (word[pos] != ch) return false;
        for (int k=0; k<4; k++) {
            board[i][j] = 0;
            bool ret = dfs(board, word, pos + 1, i + move[k], j + move[k+4]);
            board[i][j] = ch;
            if (ret) return true;
        }
        return false;
    }
};

using namespace std::chrono;

int main() {
    char* chartable[] = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaab"};
    vector<vector<char> > board;
    for (int i=0; i<sizeof(chartable)/sizeof(char*); i++) {
        char* row = chartable[i];
        board.push_back(vector<char>(row, row + strlen(row)));
    }
    string word("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    steady_clock::time_point t1, t2;
    duration<double> time_span;
    
    Solution s;
    s.times = 1000;
    t1 = steady_clock::now();
        cout<<s.exist(board, word)<<endl;
    t2 = steady_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "Solution 1: " << time_span.count() << " seconds."<<endl;
    
    Solution2 s2;
    s2.times = 1000;
    t1 = steady_clock::now();
        cout<<s2.exist(board, word)<<endl;
    t2 = steady_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "Solution 2: " << time_span.count() << " seconds."<<endl;
    
    
    Solution3 s3;
    t1 = steady_clock::now();
    for (int i=1; i<1000; i++) s3.exist(board, word);
    cout<<s3.exist(board, word)<<endl;
    t2 = steady_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "Solution 3: " << time_span.count() << " seconds."<<endl;
    system("pause");
    return 0;
}

