#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
using namespace std;

class Solution {
<<<<<<< HEAD
private:
    int is[2000][2000];
public:
    int minCut(string s) {
    	int len = s.length();
		int* memo = new int[len + 1];
		memset(&is[0][0], -1, sizeof(is));
		memset(memo, 0, (len + 1) * sizeof(int));
		
=======
public:
    int minCut(string s) {
    	int len = s.length();
		int*  p_dp = new int[len + 1];
		char* s_dp = new char[len * len];
		int*  mm = new int[len + 1];
		mm[0] = 0;
		memset(s_dp, -1, len * len);
		memset(p_dp, 0, (len + 1) * sizeof(int));

>>>>>>> 6fdada837509df2f056f3c4afdebe073b043349b
		int ret;
		for (int i=1; i<=len; i++) {
			int sub_len = i;
			int minc = INT_MAX;
<<<<<<< HEAD
			
			for (int j=0; j<=i-1; j++, sub_len--) {
				
				int* p_is = &is[j][i-1];
				
				if (*p_is == 0) continue;
				if (*p_is == -1) {
					string sub = s.substr(j, sub_len);
					int p=0, q = sub_len - 1;
					
					for (; p < q; p++, q--) {
						if (sub[p] != sub[q]) break;
					}
					if (p < q) {
						*p_is = 0;
						continue;
					}
					*p_is = 1;
				}
                if (memo[j] < minc) minc = memo[j];
                if (j == 0) break;
=======

			for (int j=0; j<=i-1; j++, sub_len--) {

				char* p_is = &s_dp[j * len + i-1];
				char b = 0;
                if (sub_len >= 3 && -1 != (b = s_dp[(j+1) * len + i - 2])) {
                    *p_is = b && (s[j] == s[j + sub_len - 1]);
                }
				if (*p_is == -1) {
					int p = j, q = j + sub_len - 1;
					for (; p < q && s[p] == s[q]; p++, q--);
					*p_is = (p < q) ? 0 : 1;
				}
				if (*p_is == 0) continue;
                if (p_dp[j] < minc) minc = p_dp[j];
                if (minc == mm[j]) break;
>>>>>>> 6fdada837509df2f056f3c4afdebe073b043349b
			}
			p_dp [i] = minc + 1;
			mm[i] = p_dp[i];
			for (int k = i-1; k >=0 && mm[k]>mm[k+1]; k--) {
                mm[k] = mm[k+1];
            }
		}
		ret = p_dp[len];
		delete[] mm;
		delete[] p_dp;
		delete[] s_dp;
		return ret - 1;
    }
};
int main() {
	// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    Solution s;
    cout<<s.minCut("aa")<<endl;
	system("pause");
	return 0;
}

