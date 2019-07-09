class Solution {
 public:
  map<string, bool> used;
  int back(int k, string result, string &tiles) {
    int sum = 0;
    if (used[result] == 0 && result != "") {
      used[result] = 1;
      sum++;
    }
    if (k == tiles.length()) {
      return sum;
    }
    for (int i = 0; i < tiles.length(); i++) {
      if (tiles[i] != '*') {
        char before = tiles[i];
        tiles[i] = '*';
        sum += back(k + 1, result + before, tiles);
        tiles[i] = before;
      }
    }
    return sum;
  }
  int numTilePossibilities(string tiles) { return back(0, "", tiles); }
};