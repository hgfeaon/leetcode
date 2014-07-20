#include <iostream>
#include <cstdlib>
#include <unordered_map>

using namespace std;

class Solution {
private:
    const static char* pattern[];
    const static char* roman[];
    unordered_map<string, int> a2i;
public:
    int romanToInt(string s) {
        int res = 0;
        if (a2i.size() == 0) build_tlb();
        
        while (!s.empty()) {
            int len = s.length();
            for (int i=min(4, len); i>0; i--) {
                unordered_map<string, int>::iterator iter = a2i.find(s.substr(len-i));
                if (iter == a2i.end()) continue;
                res += iter->second;
                s.resize(len - i);
                break;
            }
        }
        
        return res;
    }
    
    void build_tlb() {
        int pw = 1;
        for (int i=0; i<3; i++) {
            for (int j=1; j<=9; j++) {
                string rm;
                for (int k=0; pattern[j][k] != '\0'; k++) {
                    rm.push_back(roman[i][ pattern[j][k] - '0' ]);
                }
                a2i.insert(make_pair(rm, pw * j));
            }
            pw *= 10;
        }
    
        a2i.insert(make_pair("M", 1000));
        a2i.insert(make_pair("MM", 2000));
        a2i.insert(make_pair("MMMM", 3000));
    }
};

const char* Solution::pattern[] = {"A", "0", "00", "000", "01", "1", "10", "100", "1000", "02"};
const char* Solution::roman[] = {"IVX", "XLC", "CDM", "M"};

int main() {
    Solution s;
    cout<<s.romanToInt("MIII")<<endl;
	system("pause");
	return 0;
}

