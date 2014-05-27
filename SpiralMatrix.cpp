#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		    vector<int> spiralOrder(vector<vector<int> > &matrix) {
				        vector<int> ret;
						int cols = 0;
						int rows = 0;
						if (!(rows = matrix.size()) || !(cols = matrix[0].size())) {
							return ret;
						}
						int left = 0, top = 0, right = cols - 1, bottom = rows - 1;
						while (left <= right && top <= bottom) {
						    circle_walk(left, top, right, bottom, matrix, ret);
							left++, top++, bottom--, right--;
						}
						return ret;
			}

		    void circle_walk(int left, int top, int right, int bottom, vector<vector<int> >& map, vector<int>& path) {
			        int rows = 0;
			        if (map.size() < 1 || map[0].size() < 1) return;
					        
			        // top row
			        for (int i=left; i<=right; i++) {
			            path.push_back(map[top][i]);
			        }

			        // right col
			        for (int i=top+1; i<=bottom; i++) {
			            path.push_back(map[i][right]);
			        }
					
			        // bottom row
			        for (int i=right-1; bottom != top && i>=left; i--) {
			            path.push_back(map[bottom][i]);
			        }

			        // left col
			        for (int i=bottom-1; left != right && i>top; i--) {
			            path.push_back(map[i][left]);
			        }
		    }
};

void print(vector<int>& list) {
	    int len = list.size();
		    for (int i=0; i<len; i++) {
				        cout<<list[i]<<" ";    
						    }
			    cout<<endl;
}
int main() {
	    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		    vector<vector<int> > mat;
			    for (int i=0; i<3; i++) {
					        mat.push_back(vector<int>(nums + 3*i, nums + 3*i + 3));
							    }
				    
				    for (int i=0; i<3; i++) print(mat[i]);
					    
					    Solution s;

						    vector<int> path = s.spiralOrder(mat);
							    print(path);
								    return 0;
}
