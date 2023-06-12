// Given a positive integer num, return true if num is a perfect square or false otherwise.

// A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

// You must not use any built-in library function, such as sqrt.

bool isPerfectSquare(int num){
    long long l = 1;
    long long r = num;
    while (l <= r) {
        long long m = (r + l) / 2;
        long long squ = m * m;
        if (squ == num) {
            return true;
        } else if (m*m > num) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return false;
}