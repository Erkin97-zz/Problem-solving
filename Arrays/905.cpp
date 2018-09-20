#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    static vector<int> sortArrayByParity(vector<int>& A) {
      int left = 0;
      int right = A.size() - 1;
      while(left < right) {
        if (A[left] % 2 != 0 && A[right] % 2 == 0) {
          swap(A[left], A[right]);
        }
        if (A[left] % 2 == 0) left++;
        if (A[right] % 2 != 0) right--;
      }
      return A;
    }
};
// this part is for testing
int main () {
  int n;
  vector <int> test;
  cin >> n;
  test.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> test[i];
  }
  test = Solution::sortArrayByParity(test);
  for (int i = 0; i < n; i++) {
    cout << test[i] << " ";
  }
  cout << endl;
}