#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
#define SINGLE 1
#define MULTIP 2
private:
	unordered_map<unsigned int, bool> memo;
public:
    bool isMatch(const char *s, const char *p) {
    	if (s == NULL || p == NULL) return true;
		memo.clear();
		
		vector<pair<char, int> > pattern;
		
		int 	pos = 0;
		char 	ch = '\0';
		
		while ((ch = p[pos++]) != '\0') {
			if (ch == '*') {
				pattern.back().second = MULTIP;
				continue;
			}
			pattern.push_back(make_pair(ch, SINGLE));
		}
		
		return isMatch(s, 0, pattern, 0);
    }
    
    bool isMatch(const char *s, int pos, vector<pair<char, int> > &pattern, int ppos) {
    	unsigned int id = (pos << 16) | ppos;
    	
    	unordered_map<unsigned int, bool>::iterator iter = memo.find(id);
		if (memo.find(id) != memo.end()) return iter->second;
		
		bool res = false;
		
		if (ppos == pattern.size()) {
			res = s[pos] == '\0';
			memo.insert(make_pair(id, res));
			return res;
		}
		int i = pos;
		pair<char, int> &p = pattern[ppos];

		int 	offset = (p.second == SINGLE) ? 0 : -1;
		char 	ch = '\0';
		while (offset < 0 || (ch = s[pos + offset]) != '\0') {
			if (offset >= 0 && !cmp(ch, p.first)) {
				res = false;
				break;
			}
			if (isMatch(s, pos + offset + 1, pattern, ppos + 1)) {
				res = true;
				break;
			}
			if (p.second == SINGLE) break;
			offset++;
		}
		memo.insert(make_pair(id, res));
		return res;
	}
	
	bool cmp(const char a, const char b) {
		if (a == '.' || b == '.') return true;
		return a == b;
	}
};

int main() {
	Solution s;
	cout<<s.isMatch("aa", "a")<<endl;
	return 0;
}