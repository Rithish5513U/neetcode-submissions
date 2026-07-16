class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n < 0) x = 1/x;
        n = abs(n);
        if(n & 1) return myPow(x*x, n/2)*x;
        return myPow(x*x, n/2);
    }
};
