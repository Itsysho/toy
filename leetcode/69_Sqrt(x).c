// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
// You must not use any built-in exponent function or operator.
// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

int mySqrt(int x){
    if (x == 0)
        return 0;
    int l = 1;
    int r = x;
    int ret = l;
    while (l <= r) {
        int m = l + (r-l)/2;
        if (x/m/m > 0)
            l = m + 1, ret = m;
        else
            r = m - 1;
    }
    return ret;
}