#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
      vector <int> ans;
      for (int i = 0; i < A.size(); i++) {
          if (A[i] % 2 == 0) {
              ans.insert(ans.begin(), A[i]);
          } else {
              ans.push_back(A[i]);
          }
      }
      return ans;
    }
};