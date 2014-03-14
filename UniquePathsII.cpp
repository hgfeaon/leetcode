#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        vector<vector<int> >& dp = obstacleGrid;
        if (dp.empty() || dp[0].empty()) return 0;
        dp[0][0] = (dp[0][0] == 1) ? 0 : 1;
        for (int i=1; i<dp.size(); i++) {
            dp[i][0] = (dp[i][0] == 1) ? 0 : dp[i-1][0];
        }
        for (int i=1; i<dp[0].size(); i++) {
            dp[0][i] = (dp[0][i] == 1) ? 0 : dp[0][i-1];
        }
        for (int i=1; i<dp.size(); i++) {
            for (int j=1; j<dp[i].size(); j++) {
                dp[i][j] = (dp[i][j] == 1) ? 0 : dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp.back().back();
    }
};

int main() {
    int obstacle_grid[] = { 0,0,1,
                            0,1,0,
                            0,0,0};
    vector<vector<int> > grid;
    for (int i=0; i<3; i++) grid.push_back(vector<int>(obstacle_grid + i*3, obstacle_grid + i*3 + 3));
    
    Solution s;
    
    cout<<s.uniquePathsWithObstacles(grid)<<endl;
    return 0;
}
