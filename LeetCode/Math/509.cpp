class Solution {
 public:
  int fib(int N) {
    int a, b, c;
    a = 0, b = 1;
    if (N == 0) return a;
    if (N == 1) return b;
    while (N-- != 1) {
      c = a + b;
      a = b;
      b = c;
    } 
    return c;
  }
};