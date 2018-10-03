#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> findPairsWithGivenDifference( const vector<int>& arr, int k) 
{
  unordered_map<int,int> hash_table;
  for (int i = 0; i < arr.size(); i++) {
    hash_table[arr[i]] = 1;
  }
  vector <vector<int> > ans;
  for (int i = 0; i < arr.size(); i++) {
    int x, y;
    y = arr[i];
    x = y + k;
    if (hash_table[x] != 0) {
      vector <int> pair = {x, y};
      ans.push_back(pair);
    }
  }
  return ans;
}

int main() {
  return 0;
}