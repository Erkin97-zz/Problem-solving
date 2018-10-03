#include <iostream>
#include <string>

using namespace std;
int deletionDistance(const string& str1, const string& str2) {
  int d[1000][1000] = {0};
  int n = str1.length();
  int m = str2.length();
  int i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= m; j++) {
      if (i == 0) {
        d[i][j] = j;
      } else if (j == 0) {
        d[i][j] = i;
      } else if (str1[i - 1] != str2[j - 1]) {
        d[i][j] = 1 + min(d[i - 1][j], d[i][j - 1]);
      } else {
        d[i][j] = d[i - 1][j - 1];
      }
    }
  }
  return d[n][m];
}

int main() { return 0; }