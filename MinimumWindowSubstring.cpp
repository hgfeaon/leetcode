#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
private:
    int shd_cnt[256];
    int cur_cnt[256];
public:
    string minWindow(string S, string T) {
        int slen = S.length();
        int tlen = T.length();
        
        // array to store char stat info of string T
        for (int i=0; i<256; i++) shd_cnt[i] = cur_cnt[i] = 0;
        // collect char stat info of string T
        for (int i=0; i<tlen; i++) shd_cnt[T[i]]++;
        
        int shd_match_cnt = 0, cur_match_cnt = 0;
        for (int i=0; i<256; i++) shd_match_cnt += shd_cnt[i] != 0;
        
        int start = 0, end = 0;
        
        int mlen = INT_MAX, ps = 0, pe = 0;
        
        bool updated = true;
        
        while (updated) {
            updated = false;
            while (cur_match_cnt == shd_match_cnt && start < slen) {
                if (end - start < mlen) {
                    mlen = end - start;
                    ps = start, pe = end;
                }
                
                char ch = S[start];
                // whether current char is critical for matching
                // if so it could not be omitted
                if (cur_cnt[ch] - 1 < shd_cnt[ch]) break;

                updated = true;
                cur_cnt[ch]--;
                start++;
            }
            
            if (end < slen) {
                updated = true;
                char ch = S[end++];
                
                if (++cur_cnt[ch] == shd_cnt[ch]) { // using strict equal
                    cur_match_cnt++;
                }
            }
        }
        return S.substr(ps, pe - ps);
    }
};

int main() {

    Solution s;
    cout<<s.minWindow("ab", "a")<<endl;
	return 0;
}

