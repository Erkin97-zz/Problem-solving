/*
0. REMOVE ALL PUNCTUATION
1. convert all to lowercase (O(n))
2. use hash table to count number of occurances (O(n))
3. sort (O(N*logN)) quick with some comparator
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map <string, int> h_table_order;
bool comparator(pair<int, string> &a, pair <int, string> &b) {
  if (a.first == b.first ) 
    return h_table_order[a.second] < h_table_order[b.second];
  return a > b;
}
string int_to_string(int n){
  string string_number = "";
  while (n > 0) {
    int k = n % 10;
    string_number = char(k + 48) + string_number;
    n /= 10;
  }
  return string_number;
}
vector<vector<string>> wordCountEngine( const string& document ) {
  unordered_map <string, int> h_table;
  vector <vector <string> > ans;
  string document_b = "";
  for (int i = 0; i < document.length(); i++) { // case insensitive
    if (ispunct(document[i])) {
      if (document[i] != ' ')
        continue;
    }
    document_b += tolower(document[i]);
  }
  string word = "";
  document_b += "."; // end of document
  for (int i = 0; i < document_b.length(); i++) {
    if (document_b[i] == ' ' || document_b[i] == '.'
       || document_b[i] == ',' || document_b[i] == '!' || document_b[i] == '?') {
      if (word == "") continue;
      if (h_table[word] == 0) { // first time
        h_table_order[word] = i;
      }
      h_table[word]++;
      word = "";
     } else {
      word += document_b[i];
    }
  }
  vector <pair <int, string> > sort_me;
  for (unordered_map <string, int>::iterator it = h_table.begin(); it != h_table.end(); it++) {
    sort_me.push_back(make_pair(it->second, it->first));
  }
  sort(sort_me.begin(), sort_me.end(), comparator);
  for (int i = 0; i < sort_me.size(); i++) {
    vector <string> element;
    element.push_back(sort_me[i].second);
    element.push_back(int_to_string(sort_me[i].first));
    ans.push_back(element);
  }
  h_table_order.clear();
  return ans;
}

int main() {
  string test = "Practice makes perfect. you'll only get Perfect by practice. just!";
  wordCountEngine(test);
  return 0;
}