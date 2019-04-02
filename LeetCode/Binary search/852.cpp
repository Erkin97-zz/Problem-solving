class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& A) {
    int l = 0, r = A.size() - 1;
    while (l < r) {
      int m = (l + r) / 2;
      if (A[m] < A[m + 1]) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return l;
  }
};