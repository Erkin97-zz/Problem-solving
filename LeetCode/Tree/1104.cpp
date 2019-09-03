class Solution {
 public:
  vector<int> pathInZigZagTree(int label) {
    vector<int> result;
    while (label > 0) {
      result.push_back(label);
      label /= 2;
    }
    reverse(result.begin(), result.end());
    cout << result.size() << endl;
    int left = 1, right = 2;
    for (int i = 0; i < result.size(); i++) {
      if (i % 2 != 0) {
        if (result.size() % 2 != 0) {
          result[i] = (right - result[i] - 1) + left;
        }
      } else {
        if (result.size() % 2 == 0) {
          result[i] = (right - result[i] - 1) + left;
        }
      }
      left = right;
      right *= 2;
    }
    return result;
  }
};