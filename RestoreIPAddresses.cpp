#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ips;
        vector<int> ip;
        dfs(s, 0, ip, ips);
        return ips;
    }
    
    void dfs(string& s, int pos, vector<int>& ip, vector<string>& ips) {
        int len = s.length();
        int fid = ip.size();
        if (len == pos) {
            if (fid == 4) {
                ips.push_back(intip2str(ip));
            }
            return;
        }
        
        if (3 * (4 - fid) < len - pos) return;
        
        int cur = 0;
        for (int i=pos; i<len && i < pos+3; i++) {
        	if (i != pos && cur == 0) break;
            cur = cur * 10 + s[i] - '0';
            if (cur > 255) break;
            ip.push_back(cur);
            dfs(s, i + 1, ip, ips);
            ip.pop_back();
        }
    }
    
    string intip2str(vector<int> &ip) {
        if (ip.size() != 4 ) {
            return "format error. number of fields should be 4";
        }
        string strip;
        for (int i=0; i<4; i++) {
        	cout<<ip[i]<<endl;
            strip.append(std::to_string(ip[i]));
            strip.append(i==3 ? "" : ".");
        }
        return strip;
    } 
};

int main() {
	string ipnum = "010010";
	Solution s;
	vector<string> res = s.restoreIpAddresses(ipnum);
	for (int i=0; i<res.size(); i++) {
		cout<<res[i]<<endl;
	}
	system("pause");
	return 0;
}

