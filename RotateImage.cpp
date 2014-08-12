#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int end = n / 2;
        for (int i=0; i<end; i++) {
            for (int j=i; j < n - i - 1; j++) {
                int a = matrix[i][j];
                int b = matrix[j][n-1-i];
                int c = matrix[n-1-i][n-1-j];
                int d = matrix[n-1-j][i];
                matrix[i][j] = d;
                matrix[j][n-1-i] = a;
                matrix[n-1-i][n-1-j] = b;
                matrix[n-1-j][i] = c;
            }
        }
    }
};

void print(vector<vector<int> > &m) {
	for (int i=0; i<m.size(); i++) {
		for (int j=0; j<m[i].size(); j++) {
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int main() {
	vector<vector<int> > m;
	vector<int> row;
	row.push_back(1);
	row.push_back(2);
	m.push_back(row);
	row[0] = 3;
	row[1] = 4;
	m.push_back(row);
	
	print(m);
	
	Solution s;
	s.rotate(m);
	
	print(m);
	
	system("pause");
	return 0;
}

