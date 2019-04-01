class Solution {
 public:
  vector<int> diStringMatch(string S) {
    int n = S.length(), minimum = 0, maximum = n;
    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++) {
      if (S[i] == 'I') {
        ans[i] = minimum++;
      } else {
        ans[i] = maximum--;
      }
    }
    ans[n] = minimum;
    return ans;
  }
};