#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
    	int len = path.length();
		if (len < 2) return "/";

		vector<string> spath;

		int p = -1, q = 0;

		// seperate the path into parts & simplify it with a stack
		while (q < len) {
			while (q < len && path[q] != '/') q++;
			if (p + 1 < q) {
				add_part_to_spath(path.substr(p + 1, q - p - 1), spath);
			}
			p = q;
			q++;
		}

		// build the final simplified path
		string res;
		for (int i=0; i<spath.size(); i++) {
			res.push_back('/');
			res.append(spath[i]);
		}
		if (res.length() == 0) res = "/";
		return res;

	}

	void add_part_to_spath(string part, vector<string>& spath) {
		if (part == ".") {
			// do nothing;
		} else if (part == "..") {
			// goto the parent path part
			if (!spath.empty()) spath.pop_back();
		} else {
			// enter a new part
			spath.push_back(part);
		}

	}
};

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout<<"Usage: \n\t"<<argv[0]<<" <path_to_simplify>"<<endl;
		return 0;
	}
	Solution s;
	cout<<"orginal  : "<<argv[1]<<endl;
	cout<<"simplifid: "<<s.simplifyPath(argv[1])<<endl;
	return 0;
}
