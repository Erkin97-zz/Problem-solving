#include <iostream>
#include <vector>

using namespace std;

int findBusiestPeriod( const vector<vector<int> >& data ) {
  int max_value = 0, max_time;
  int current = 0;
  int i;
  for (i = 0; i < data.size(); i++) {
    data[i][2] ? current += data[i][1] : current -= data[i][1];
    if (i == data.size() - 1 || data[i][0] != data[i+1][0]) {
      if (current > max_value) {
        max_value = current;
        max_time = data[i][0];
      }
    } 
  }
  return max_time;
}

int main() {
  return 0;
}