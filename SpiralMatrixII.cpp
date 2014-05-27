#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
	public:
		    vector<vector<int> > generateMatrix(int n) {
				vector<vector<int> > matrix;
				if (n < 1) return matrix;

				for (int i=0; i<n; i++) {
					matrix.push_back(vector<int>(n, 0));
				}
				int left = 0, top = 0, right = n - 1, bottom = n - 1;
				int last = 1;
				while (left <= right && top <= bottom) {
				    last = circle_walk(last, left, top, right, bottom, matrix);
					left++, top++, bottom--, right--;
				}
				return matrix;
			}

		    int circle_walk(int start, int left, int top, int right, int bottom, vector<vector<int> >& map) {
			        int rows = 0;
			        if (map.size() < 1 || map[0].size() < 1) return start;
					        
			        // top row
			        for (int i=left; i<=right; i++) {
			        	map[top][i] = start++;
			        }

			        // right col
			        for (int i=top+1; i<=bottom; i++) {
			           map[i][right] = start++;
			        }
					
			        // bottom row
			        for (int i=right-1; bottom != top && i>=left; i--) {
			            map[bottom][i] = start++;
			        }

			        // left col
			        for (int i=bottom-1; left != right && i>top; i--) {
			            map[i][left] = start++;
			        }
					return start;
		    }
};

void print(vector<int>& list) {
	int len = list.size();
	for (int i=0; i<len; i++) {
		printf("%3d ", list[i]);
	}
	cout<<endl;
}
int main(int argc, char* argv[]) {
				    
	int n = 4;

	Solution s;
	
	vector<vector<int> > mat = s.generateMatrix(n);
	
	for (int i=0; i<n; i++) {
		print(mat[i]);
	}

	return 0;
}
