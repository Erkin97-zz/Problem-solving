#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {
  for (int i = 0; i < s.length(); i++) {
    if (!isalpha(s[i])) continue;
    if (islower(s[i]))
      s[i] = ((s[i] - 97 + k) % 26) + 97;
    else
      s[i] = ((s[i] - 65 + k) % 26) + 65;
  }
  return s;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string s;
  getline(cin, s);

  int k;
  cin >> k;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string result = caesarCipher(s, k);

  fout << result << "\n";

  fout.close();

  return 0;
}
