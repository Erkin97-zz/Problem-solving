class Solution {
 public:
  vector<string> findOcurrences(string s, string first, string second) {
    string w1 = "", w2 = "", w3 = "";
    vector<string> result;
    s += ' ';
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ' ') {
        if (w1 == first && w2 == second) {
          result.push_back(w3);
        }
        w1 = w2;
        w2 = w3;
        w3 = "";
      } else {
        w3 += s[i];
      }
    }
    return result;
  }
};