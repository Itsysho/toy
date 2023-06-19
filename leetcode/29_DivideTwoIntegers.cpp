// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

// The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

// Return the quotient after dividing dividend by divisor.

// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the quotient is strictly less than -2^31, then return -2^31.


class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        int sign = 1;
        unsigned int a;
        unsigned int b = divisor;
        if (dividend < 0)
            sign = -sign, a = abs(dividend);
        else
            a = dividend;
        if (divisor < 0)
            sign = -sign, b = abs(divisor);
        else
            b = divisor;
        if (a < b) return 0;

        int ret = 0;
        int top = 0;
        unsigned int tmp = b;
        while (tmp)
            tmp >>= 1, top++;
        for (int i = 32-top; i >= 0; i--) {
            if ((a >> i) == 0)
                continue;
            if ((b << i) <= a) {
                a -= b << i; 
                ret |= 1 << i; 
            }
        }
        return sign == 1 ? ret : -ret;
    }
};