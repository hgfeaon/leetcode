#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        if (n < 1) return 0;
        vector<int> peaks;

        int last_idx = 0;

        bool increasing = true;
        for (int i=1; i<n; i++) {
            if (A[i] < A[last_idx]) {
                if (increasing) {
                    peaks.push_back(last_idx);
                    compact(A, peaks);
                }
                increasing = false;
            } else {
                increasing = true;
            }
            last_idx = i;
        }
        
        if (increasing) peaks.push_back(n - 1);
        compact(A, peaks);
        
        int rain = 0;

        for (int i=1; i<peaks.size(); i++) {
            int left = peaks[i - 1];
            int right= peaks[i];

            int h = min(A[left], A[right]);
            int blocks = 0;
            for (int i=left + 1; i<right; i++) blocks += A[i] > h ? h : A[i];
            rain += h * (right - left - 1) - blocks;
        }
        return rain;
    }

    void compact(int A[], vector<int> &peaks) {
        int len = peaks.size();
        if (len < 3) return;
        bool updated = true;
        while (updated && (len = peaks.size()) >= 3) {
            updated = false;
            int ai = peaks[len - 3];
            int bi = peaks[len - 2];
            int ci = peaks[len - 1];
            if (A[ai] >= A[bi] && A[ci] >= A[bi] ) {
                peaks[len - 2] = ci;
                peaks.pop_back();
                updated = true;
            }
        }
    }
    
    void print(vector<int> &array) {
        for (int i=0; i<array.size(); i++) {
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }

    int trap2(int A[], int n) {
        if (n < 2) return 0;
        vector<int> lmax(n, 0);
        vector<int> rmax(n, 0);
        
        int m = A[n-1];
        for (int i=n-2; i >= 0; i--) {
            if (A[i] > m) m = A[i];
            rmax[i] = m;
        }
        
        m = A[0];
        for (int i=1; i<n; i++) {
            if (A[i] > m) m = A[i];
            lmax[i] = m;
        }

        int rain = 0;
        for (int i=0; i<n; i++) {
            int h = min(lmax[i], rmax[i]);
            int v = h - A[i];
            rain += v < 0 ? 0 : v;
            
        }
        return rain;
    }
};


int main() {
    int blocks[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int blocks2[] = {5,2,1,2,1,5};
    
    int len = sizeof(blocks) / sizeof(int);
    int len2 = sizeof(blocks2) / sizeof(int);

    Solution s;

    cout<<s.trap(blocks, len)<<endl;
    cout<<s.trap(blocks2, len2)<<endl;
    
    cout<<s.trap2(blocks, len)<<endl;
    cout<<s.trap2(blocks2, len2)<<endl;
    
	system("pause");
	return 0;
}

