// You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

// Given the integer n, return the number of complete rows of the staircase you will build.

int arrangeCoins(int n){
    int l = 1;
    int r = sqrt(n) * 2;
    int ret = 1;
    while (l <= r) {
        long long m = (l + r)  / 2;
        long long sum = (1 + m) * m / 2;
        if (sum <= n) {
            l = m + 1;
            ret = m;
        } else {
           r = m - 1;
        }
    }
    return ret;
}