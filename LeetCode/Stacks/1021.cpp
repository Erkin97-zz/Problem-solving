class Solution {
public:
  string removeOuterParentheses(string S) {
    string result = "";
    int balance = 0;
    for (int i = 0; i < S.length(); i++) {
      if (balance > 0 && !(balance == 1 && S[i] == ')')) {
        result += S[i];
      }
      if (S[i] == '(') {
        balance++;
      }
      else if (balance > 0) {
        balance--;
      }
    }
    return result;
  }
};