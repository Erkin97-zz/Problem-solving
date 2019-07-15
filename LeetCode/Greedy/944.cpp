class Solution {
 public:
  int minDeletionSize(vector<string>& A) {
    if (A.size() == 0) {
      return 0;
    }
    int sum = 0;
    for (int j = 0; j < A[0].length(); j++) {
      for (int i = 0; i < A.size() - 1; i++) {
        if (A[i][j] > A[i + 1][j]) {
          sum++;
          break;
        }
      }
    }
    return sum;
  }
};