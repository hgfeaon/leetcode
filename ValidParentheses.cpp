class Solution {
public:
    bool isValid(string s) {
        char open[] = {'(', '[', '{'};
        char close[]= {')', ']', '}'};
        
        int count[3] = {0, 0, 0};
        
        vector<char> last_open;
        int k;
        for (int i=0; i<s.size(); i++) {
            char cur = s[i];
            for (k=0; k<3 && cur != open[k]; k++);
            if (k < 3) {
                count[k]++;
                last_open.push_back(open[k]);
                continue;
            }
            
            for (k=0; k<3 && cur != close[k]; k++);
            if (k == 3) continue; // should not be happened
            if (--count[k] < 0 || open[k] != last_open.back()) {
                return false;
            } else {
                last_open.pop_back();
            }
        }
        
        return (last_open.size() == 0) && !(count[0] | count[1] | count[2]);
    }
};