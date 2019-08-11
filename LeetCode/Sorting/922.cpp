class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& A) {
    int even = 0, odd = 1;
    while (even < A.size()) {
      if (A[even] % 2 != 0) {
        while (A[odd] % 2 != 0) {
          odd += 2;
        }
        swap(A[even], A[odd]);
      } else {
        even += 2;
      }
    }
    return A;
  }
};