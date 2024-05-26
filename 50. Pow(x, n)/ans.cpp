class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            return 1.0/ myPow64(x, -(int64_t)n);
        } else {
            return myPow64(x, (int64_t)n);
        }
    }
    double myPow64(double x, int64_t n) {
        if (n == 0)
            return 1.0;
        return (n%2==0 ? 1.0 : x) * myPow64(x*x, n/2);
    }
};
