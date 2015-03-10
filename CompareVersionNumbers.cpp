#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int compareVersion2(string version1, string version2) {
        int part1 = 0;
        int part2 = 0;
        int len1 = version1.length();
        int len2 = version2.length();
        
        int i = 0, j = 0;
        while (i < len1 || j < len2) {
            char ch;
            while (i < len1 && (ch = version1[i++]) != '.') {
                part1 += ch - '0' + part1 * 10;
            }

            while(j < len2 && (ch = version2[j++]) != '.') {
                part2 += ch - '0' + part2 * 10;
            }
            if (part1 > part2) {
                return 1;
            } else if (part1 < part2) {
                return -1;
            } else {
                // part equal, continue to compare next version part
            }
            part1 = part2 = 0;
        }
        
        return 0;
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1 = getVersionParts(version1);
        vector<int> v2 = getVersionParts(version2);

        int i = 0, j = 0;
        int len1 = v1.size();
        int len2 = v2.size();


        while (i < len1 && j < len2) {
            if (v1[i] < v2[i]) {
                return -1;
            } else if (v1[i] > v2[i]) {
                return 1;
            }
            i++, j++;
        }
        int r = 0;
        while (i < len1) {
            r += v1[i++];
        }
        if (r != 0) {
            return 1;
        }
        r = 0;
        while (j < len2) {
            r += v2[j++];
        }
        if (r != 0) {
            return -1;
        }
        return 0;
    }

    vector<int> getVersionParts(string& version) {
        vector<int> parts;
        int len = version.length();
        int v = 0;
        char d = '\0';
        for (int i=0; i<len; i++) {
            d = version[i];
            if (d == '.') {
                parts.push_back(v);
                v = 0;
                continue;
            }

            v = v * 10 + d - '0';
        }
        if (d != '.') {
            parts.push_back(v);
        }
        return parts;
    }
};

int main() {
    Solution s;
    cout<<s.compareVersion2("1.0", "1.02")<<endl;;
	system("pause");
	return 0;
}

