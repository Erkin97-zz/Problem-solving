#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
  if (s == "")
    return s;

  stack<char> st;

  for (int i = 0; i < s.length(); i++) {
    if (!st.empty() && st.top() == s[i]) {
      st.pop();
    } else
      st.push(s[i]);
  }
  string result = "";
  while (!st.empty()) {
    result = st.top() + result;
    st.pop();
  }
  return result;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  string result = superReducedString(s);

  if (result == "") {
    result = "Empty String";
  }

  fout << result << "\n";
  fout.close();

  return 0;
}