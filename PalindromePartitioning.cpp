#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
    	int len = s.length();
		vector<vector<string> >* memo = new vector<vector<string> >[len + 1];
		vector<vector<string> > ret;
		
		for (int i=1; i<=len; i++) {
			int sub_len = 0;
			vector<vector<string> >& cur = memo[i];
			
			for (int j=i-1; j>=0; j--) {
				string sub = s.substr(j, ++sub_len);

				if (!is_palindrome(sub)) continue;
				
				if (j == 0) {
					cur.push_back(vector<string>(1, sub));
					continue;
				}
				
				for (int k=0; k<memo[j].size(); k++) {
					vector<string> tmp = memo[j][k];
					tmp.push_back(sub);
					cur.push_back(tmp);
				}
			}
		}
		ret = memo[len];
		delete[] memo;
		return ret;
    }
    
    bool is_palindrome(string& s) {
		int i=0, j = s.length() - 1; 
		while (i < j) {
			if (s[i++] != s[j--]) return false;
		}
		return true;
	}
};

void print(vector<vector<string> >& data) {
	for (int i=0; i<data.size(); i++) {
		cout<<"[";
		for (int j=0; j<data[i].size(); j++) {
			cout<<data[i][j]<<", ";
		}
		cout<<"]"<<endl;
	}
}

int main() {
	Solution s;
	
	vector<vector<string> > ret = s.partition("aaaaaaaaaa");
	
	print(ret);
	
	system("pause");
	return 0;
}

