class Solution {
 public:
  int matrixScore(vector<vector<int>>& A) {
    int sum = 0;
    int base = 1;
    if (A.size() == 0) return 0;
    for (int i = 0; i < A.size(); i++) {
      if (A[i][0] == 0) {
        for (int j = 0; j < A[i].size(); j++) {
          A[i][j] ^= 1;
        }
      }
    }
    for (int j = A[0].size() - 1; j >= 0; j--) {
      int num0 = 0, num1 = 0;
      for (int i = 0; i < A.size(); i++) {
        A[i][j] ? num1++ : num0++;
      }
      sum += base * max(num0, num1);
      base *= 2;
    }
    return sum;
  }
};