class Solution {
 private:
  int prepare(vector<int>& A) {
    int answer = A.size();
    for (int i = 0; i < A.size(); i++) {
      if (A[i] >= 0 && answer == A.size()) {
        answer = i;
      }
      A[i] = A[i] * A[i];
    }
    return answer;
  }

 public:
  vector<int> sortedSquares(vector<int>& A) {
    int right = prepare(A);
    vector<int> result;
    int left = right - 1;
    while (left >= 0 || right < A.size()) {
      if (left < 0) {
        result.push_back(A[right++]);
      } else if (right == A.size()) {
        result.push_back(A[left--]);
      } else if (A[left] >= A[right]) {
        result.push_back(A[right++]);
      } else {
        result.push_back(A[left--]);
      }
    }
    return result;
  }
};
