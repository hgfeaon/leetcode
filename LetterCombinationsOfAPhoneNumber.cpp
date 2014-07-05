#include <iostream>
#include <vector>
#include <string> 

using namespace std;

const char* lookup[] = {" ", "", "abc", "def",
								"ghi", "jkl", "mno", 
								"pqrs", "tuv", "wxyz" 
						};
class Solution {
public:
	vector<string> letterCombinations(string digits) {   
		string str;
		vector<string> res;

		dfs(digits, 0, str, res);
		return res;
	}
	
	void dfs(string& digits, int pos, string& str, vector<string>& res) {
		if (digits.length() <=  pos) {
			res.push_back(str);
			return;
		}
		
		const char* alphabetas = lookup[digits[pos] - '0'];
		for (int i=0; alphabetas[i] != '\0'; i++) {
			str.push_back(alphabetas[i]);
			dfs(digits, pos + 1, str, res);
			str.pop_back();
		}
	}

};

void print(vector<string>& list) {
	for (int i=0; i<list.size(); i++) {
		cout<<list[i]<<endl;
	}
}

int main () {
	Solution s;
	vector<string> letters = s.letterCombinations("23");
	print(letters);
	return 0;
}
