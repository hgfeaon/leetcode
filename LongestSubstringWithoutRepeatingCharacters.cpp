#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len < 2) return len;
        char cnt[256];
        memset(cnt, 0, sizeof(cnt));
        
        const char* p = s.c_str();
        const char* q = p + 1;
        const char* end = s.c_str() + len - 1;
        
        int mlen = 1;
        cnt[*p] = 1;
        
        while(q <= end) {
            char ch = *q;
            int clen = q - p + (ch == 0);
            
            if (cnt[ch]) { // the character ch already exist in substr[p,q]
                for(;*p != ch; p++) cnt[*p] = 0;
                p++;
            } else {
                cnt[ch] = 1;
            }
            if (clen > mlen) mlen = clen;
            q++;
        }
        
        return mlen;
    }
};

int main() {
    Solution s;
    cout<<s.lengthOfLongestSubstring("abcabcdssew")<<endl;
    system("pause");
    return 0;    
}
