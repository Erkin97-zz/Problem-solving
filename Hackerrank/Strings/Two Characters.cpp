#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the alternate function below.
int alternate(string s) {
  int ans = 0;
  string s_buff;
  for (char i = 'a'; i <= 'z'; i++) {
    for (char j = i + 1; j <= 'z'; j++) {
      s_buff = "";
      bool f = true;
      int n = 0;
      for (int k = 0; k < s.length(); k++) {
        if (s[k] == i || s[k] == j) {
          s_buff += s[k];
          if (n > 0 && s_buff[n] == s_buff[n - 1]) {
            f = false;
            break;
          }
          n++;
        }
      }
      if (f && n > 1) {
        cout << s_buff << endl;
        ans = max(n, ans);
      }
    }
  }
  cout << ans << endl;
  return ans;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string l_temp;
  getline(cin, l_temp);

  int l = stoi(ltrim(rtrim(l_temp)));

  string s;
  getline(cin, s);

  int result = alternate(s);

  fout << result << "\n";

  fout.close();

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}
