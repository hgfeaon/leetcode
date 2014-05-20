#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        cout<<"="<<s1<<","<<s2<<endl;
        int len = s1.length();
        if (len == 1 && s1[0] == s2[0]) return true;
        
        int a_st_front[256] = {0};
        int b_st_back[256]  = {0};
        // int a_st_back[256]  = {0};
        int b_st_front[256] = {0};
        
        for (int i=0; i<len-1; i++) {
            a_st_front[ s1[i] ]++;
            b_st_back[ s2[len - i - 1] ]++;
            
            if ( is_alphabeta_stat_equal(a_st_front, b_st_back, 256) ) {
                if ( isScramble(s1.substr(0, i + 1), s2.substr(len - i - 1, i+1))
                    && isScramble(s1.substr(i + 1, len - i - 1), s2.substr(0, len - i - 1)) ) {
                        return true;
                }
            }
            
            b_st_front[ s2[i] ]++;

            if ( is_alphabeta_stat_equal(b_st_front, a_st_front, 256) ) {
                if ( isScramble( s1.substr(0, i + 1), s2.substr(0, i + 1) )
                    && isScramble(s1.substr(i + 1, len - i - 1), s2.substr(i + 1, len - i - 1)) ) {
                        return true;
                }
            }
        }
        return false;
    }

    bool is_alphabeta_stat_equal(int* a, int *b, int len) {
        for (int i=0; i<len; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout<<s.isScramble("aaaaaaaaaaaaaaabaa", "aaaaaaaaaaaaaaaaab")<<endl;
	system("pause");
	return 0;
}

