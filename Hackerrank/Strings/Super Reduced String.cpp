#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
  cout << s << endl;
  if (s.length() < 2) return s;

  bool f = true;

  while (f) {
    string s_new = "";
    for (int i = 0; i < s.length(); i++) {
      if (i != s.length() - 1 && s[i] == s[i + 1]) {
        cout << "Hello same" << endl;
        i++;
      } else {
        s_new += s[i];
      }
    }
    cout << s << endl;
    if (s_new == s) break;
    s = s_new;
  }
  cout << "Look at me " << s << endl;
  return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
  cout << s << endl;
  if (s.length() < 2)
    return s;

  bool f = true;

  while (f) {
    string s_new = "";
    for (int i = 0; i < s.length(); i++) {
      if (i != s.length() - 1 && s[i] == s[i + 1]) {
        i++;
      } else {
        s_new += s[i];
      }
    }
    if (s_new == s)
      break;
    s = s_new;
  }
  return s;
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


    string result = superReducedString(s);

    if (result == "") {
      result = "Empty String";
    }

    fout << result << "\n";

    fout.close();

    return 0;
}
