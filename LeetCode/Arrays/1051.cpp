class Solution {
 public:
  int heightChecker(vector<int>& heights) {
    int sum = 0;
    vector<int> h;
    h = heights;
    sort(heights.begin(), heights.end());
    for (int i = 0; i < heights.size(); i++) {
      sum += (heights[i] != h[i]);
    }
    return sum;
  }
};