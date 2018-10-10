#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, int> arr_h;

bool check(vector<char> arr, const string &str) {
  for (int i = 0; i < str.length(); i++) {
    vector<char>::iterator it = find(arr.begin(), arr.end(), str[i]);
    if (it != arr.end()) {
      arr.erase(it);
    }
  }
  return arr.empty();
}


string getShortestUniqueSubstring( const vector<char>& arr, const string &str ) 
{
  for (int i = 0; i < arr.size(); i++) {
    arr_h[arr[i]] = 1;
  }
  string answer = "";
  string buffer = "";
  for (int i = 0; i < str.length(); i++) {
    buffer = "";
    for (int j = i; j < str.length(); j++) {
      buffer += str[j];
      if(check(arr, buffer)) {
        if (buffer.length() < answer.length() || answer == "") {
          answer = buffer;
        }
        break;
      }
    }
  }
  return answer;
  // your code goes here
}

int main() {
  return 0;
}