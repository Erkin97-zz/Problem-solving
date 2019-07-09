class Solution {
 public:
  string forwarded_mail(string s) {
    string forwarded = "";
    bool is_local = true, is_plus = false;
    for (int i = 0; i < s.length(); i++) {
      if (is_local) {
        if (s[i] == '@') {
          forwarded += s[i];
          is_local = false;
        } else if (is_plus) {
          continue;
        } else if (s[i] == '.') {
          continue;
        } else if (s[i] == '+') {
          is_plus = true;
        } else {
          forwarded += s[i];
        }
      } else {
        forwarded += s[i];
      }
    }
    return forwarded;
  }
  int numUniqueEmails(vector<string>& emails) {
    map<string, bool> ma;
    for (int i = 0; i < emails.size(); i++) {
      ma[forwarded_mail(emails[i])] = true;
    }
    return ma.size();
  }
};