class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > res;
        vector<int> path;
        dfs(S, path, 0, res);
        return res;
    }
    
    void dfs(vector<int>& s, vector<int>& cur, int pos, vector<vector<int> >& res) {
        if (pos == s.size()) {
            res.push_back(cur);
            return;
        }
        // case 1. put the current number into the set
        cur.push_back(s[pos]);
        dfs(s, cur, pos + 1, res);
        cur.pop_back();
        
        // case 2. skip the current number
        dfs(s, cur, pos + 1, res);
    }
};