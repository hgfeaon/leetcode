#include <iostream>
<<<<<<< HEAD
#include <vector>
#include <cstdlib>
#include <string>
=======
#include <cstdlib>
#include <vector>
>>>>>>> 60a354dacfa1814621d22c3bcbcb1797e0bf4c99

using namespace std;

class Solution {
<<<<<<< HEAD
private:
    // used only by dfs
    vector<vector<string> > ret;
public:
    // 1. using dfs
    vector<vector<string> > partition(string s) {
        ret.clear();
        vector<string> m;
        dfs(m, s, 0, s.length() - 1);
        return ret;
    }

    void dfs(vector<string>& m, string& str, int s, int e) {
        if (s > e) {
            ret.push_back(m);
        }
        for (int i=s; i<=e; i++) {
            if (!is_palindrome(str, s, i)) continue;
            m.push_back(str.substr(s, i - s + 1));
            dfs(m, str, i+1, e);
            m.pop_back();
        }
    }


    bool is_palindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    
    // 2. dp? is it dp?
    vector<vector<string> > _partition(string s) {
    	int len = s.length();
		vector<vector<string> >* memo = new vector<vector<string> >[len + 1];
		vector<vector<string> > ret;

		for (int i=1; i<=len; i++) {
			int sub_len = 0;
			vector<vector<string> >& cur = memo[i];

			for (int j=i-1; j>=0; j--) {
				string sub = s.substr(j, ++sub_len);

				int p=0, q = sub_len - 1;
				for (; p < q; p++, q--) {
					if (sub[p] != sub[q]) break;
				}
				if (p < q) continue;

=======
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
				
>>>>>>> 60a354dacfa1814621d22c3bcbcb1797e0bf4c99
				if (j == 0) {
					cur.push_back(vector<string>(1, sub));
					continue;
				}
<<<<<<< HEAD

				for (int k=0; k<memo[j].size(); k++) {
					cur.push_back(memo[j][k]);
					cur.back().push_back(sub);
=======
				
				for (int k=0; k<memo[j].size(); k++) {
					vector<string> tmp = memo[j][k];
					tmp.push_back(sub);
					cur.push_back(tmp);
>>>>>>> 60a354dacfa1814621d22c3bcbcb1797e0bf4c99
				}
			}
		}
		ret = memo[len];
		delete[] memo;
		return ret;
    }
<<<<<<< HEAD
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
    vector<vector<string> > ret;
    ret = s.partition("aaba");
    print(ret);
    cout<<endl;
    ret = s._partition("aaba");
    print(ret);
    return 0;
=======
    
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
>>>>>>> 60a354dacfa1814621d22c3bcbcb1797e0bf4c99
}

