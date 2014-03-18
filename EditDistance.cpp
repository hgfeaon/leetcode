#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        const int cols = word1.length() + 1;
        const int rows = word2.length() + 1;
        
        int* dp = new int[cols * rows];
    
        int rowbase = 0;
        for (int i=0; i<cols; i++) dp[i] = i;
        for (int i=0; i<rows; i++, rowbase+=cols) dp[rowbase] = i;
        
        rowbase = 0;
        for (int i=1; i<rows; i++) {
            rowbase += cols;
            for (int j=1; j<cols; j++) {
                int diff = word1[j-1] != word2[i-1];
                dp[rowbase + j] = min(min(
                                        dp[rowbase + j-1] + 1, 
                                        dp[rowbase - cols + j] + 1),
                                        dp[rowbase - cols + j-1] + diff);
            }
        }
        
        int ret = dp[cols * rows - 1];
        delete[] dp;
        return ret;
    }
};

int main() {
    string s1("abc");
    string s2("ack");
    
    Solution s;
    
    cout<<s.minDistance(s1, s2)<<endl;
    
    return 0;
}

