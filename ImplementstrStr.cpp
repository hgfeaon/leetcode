#include <iostream>

using namespace std;

class Solution {
public:
	char *strStr(char *haystack, char *needle) {
		if (haystack == NULL || needle == NULL) return NULL;
		int wpos[256];
		char cur = 0;
		int len = 0;
		for (int i=0; i < 256; i++) wpos[i] = -1;
		
		for (int i=0; (cur =  needle[i]) != '\0'; i++, len++) wpos[cur] = i;
		int p = 0, q = 0;
		while (true) {
			while (haystack[p] != '\0'
					&& needle[q] != '\0'
					&& haystack[p] == needle[q]) p++, q++;
			
			if ( needle[q] == '\0') {
				return haystack + p - q;
			}

			if (haystack[p] == '\0') {
				return NULL;
			}

			int npos = p - q + len; 
			int move = wpos[haystack[npos]];
			q = 0;
			if (move < 0) {
				p++;
			} else {
				p = npos - move;
			}
		}
		return NULL;
	}
};

int main(int argc, char* argv[]) {
	if (argc < 3) {
		cout<<"Usage:\n\t"<<argv[0]<<" haystack_string needle_string"<<endl;
	}
	Solution s;
	cout<<s.strStr(argv[1], argv[2])<<endl;
	return 0;
}
