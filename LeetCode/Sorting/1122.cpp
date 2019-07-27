class Solution {
 public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    // find indexes for arr2
    int ma[1010];
    for (int i = 0; i < arr1.size(); i++) {
      ma[arr1[i]] = arr2.size() + 1;
    }
    for (int i = 0; i < arr2.size(); i++) {
      ma[arr2[i]] = i + 1;
    }
    sort(arr1.begin(), arr1.end(), [&ma](int a, int b) mutable {
      int index_a = ma[a], index_b = ma[b];
      if (index_a == index_b) {
        return a < b;
      }
      return index_a < index_b;
    });
    return arr1;
  }
};