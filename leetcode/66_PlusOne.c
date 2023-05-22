// You are given a large integer represented as an integer array digits, 
// where each digits[i] is the ith digit of the integer. 
// The digits are ordered from most significant to least significant in left-to-right order. 
// The large integer does not contain any leading 0's.

// Increment the large integer by one and return the resulting array of digits.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) { 
  int* res = (int*) malloc(sizeof(int)*digitsSize);
  int carry = 1;
  for (int i = digitsSize - 1; i >= 0; i--) {
    carry += digits[i];
    res[i] = carry % 10;
    carry /= 10;
  }
  if (carry) {
    int* next = (int*) malloc(sizeof(int)*(digitsSize+1));
    memcpy(next+1, res, sizeof(int)*digitsSize);
    next[0] = carry;
    *returnSize = digitsSize +1;
    return next;
  } else {
    *returnSize = digitsSize;
    return res;
  }
}