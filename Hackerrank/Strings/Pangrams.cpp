#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
  set <char> st;

  for (int i = 0; i < s.length(); i++) {
    if (isalpha(tolower(s[i]))) {
      st.insert(tolower(s[i]));
    }
  }
  if (st.size() == 26) {
    return "pangram";
  }
  return "not pangram";
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  string result = pangrams(s);

  fout << result << "\n";

  fout.close();

  return 0;
}
