#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
bool check_variant(int a, int b, int sum, int total) {
  if (a == b) return true;

  if (a != b) {
    a--;
    sum--;
  }

  if (a == 0) {
    total--;
    if (sum % b == 0 && sum / b == total) return true;
  } else if (a != b) {
    return false;
  } else {
    if (sum % b == 0 && sum / b == total) return true;
  }

  return false;
}
string isValid(string s) {
  unordered_map<char, int> ma;
  int second_sum, first_sum;
  int sum = 0;

  for (int i = 0; i < s.length(); i++) {
    ma[s[i]]++;
  }

  unordered_map<char, int>::iterator it = ma.begin();
  second_sum = first_sum = it->second;
  sum = first_sum;
  it++;
  bool f = true;

  for (; it != ma.end(); it++) {
    if (it->second != first_sum && it->second != second_sum) {
      if (!f) {
        return "NO";
      }
      f = false;
      second_sum = it->second;
    }
    sum += it->second;
  }
  if (check_variant(first_sum, second_sum, sum, ma.size())) return "YES";
  if (check_variant(second_sum, first_sum, sum, ma.size())) return "YES";
  return "NO";
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  string result = isValid(s);

  fout << result << "\n";

  fout.close();

  return 0;
}
