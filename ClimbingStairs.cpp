class Solution {
public:
    int climbStairs(int n) {
        if (n < 1) return 0;
        int a = 0;
        int b = 1;
        for (int i=0; i<n; i++) {
            int t = a + b;
            a = b;
            b = t;
        }
        return b;
    }    
};
