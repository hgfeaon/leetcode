class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (A == NULL || n < 1) return 0;
        int p = -1, q = n;
        while (p + 1 < q) {
            int mi = (p + q) / 2;
            if (A[mi] > target) {
                q = mi;
            } else if (A[mi] < target) {
                p = mi;
            } else {
                return mi;
            }
        }
        return q;
    }
};
