#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
  string numbers = "0123456789";
  string lower_case = "abcdefghijklmnopqrstuvwxyz";
  string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string special_characters = "!@#$%^&*()-+";

  int used[4] = {0};
  int sum = 0;

  for (int i = 0; i < n; i++) {
    if (used[0] == 0 && numbers.find(password[i]) != string::npos) {
      used[0] = 1;
      sum++;
    }
    if (used[1] == 0 && lower_case.find(password[i]) != string::npos) {
      used[1] = 1;
      sum++;
    }
    if (used[2] == 0 && upper_case.find(password[i]) != string::npos) {
      used[2] = 1;
      sum++;
    }
    if (used[3] == 0 && special_characters.find(password[i]) != string::npos) {
      used[3] = 1;
      sum++;
    }
  }
  sum = 4 - sum;
  cout << sum << endl;
  sum = sum + max(0, 6 - n - sum);
  return sum;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string password;
  getline(cin, password);

  int answer = minimumNumber(n, password);

  fout << answer << "\n";
  cout << answer << "\n";

  fout.close();

  return 0;
}