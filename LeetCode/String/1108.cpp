class Solution {
 public:
  string defangIPaddr(string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
      result += s[i];
      if (i < s.length() - 1 && s[i + 1] == '.') {
        result += "[.]";
        i++;
      }
    }
    return result;
  }
};