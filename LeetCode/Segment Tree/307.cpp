class NumArray {
 public:
  vector<int> A, Tree;
  int N;
  void build(int n, int start, int end) {
    if (start == end) {
      Tree[n] = A[start];
    } else {
      int m = (start + end) / 2;
      build(n * 2, start, m);
      build(n * 2 + 1, m + 1, end);
      Tree[n] = Tree[n * 2] + Tree[n * 2 + 1];
    }
  }

  NumArray(vector<int>& nums) {
    N = nums.size();
    A.resize(N + 1);
    Tree.resize(N * 4);
    for (int i = 0; i < N; i++) {
      A[i + 1] = nums[i];
    }
    if (N == 0) return;
    build(1, 1, N);
  }

  void tree_update(int n, int start, int end, int i, int val) {
    if (start == end) {
      Tree[n] = val;
    } else {
      int m = (start + end) / 2;
      if (i >= start && i <= m) {
        tree_update(n * 2, start, m, i, val);
      } else if (i >= m + 1 && i <= end) {
        tree_update(n * 2 + 1, m + 1, end, i, val);
      }
      Tree[n] = Tree[n * 2] + Tree[n * 2 + 1];
    }
  }

  void update(int i, int val) { tree_update(1, 1, N, i + 1, val); }

  int query(int n, int start, int end, int l, int r) {
    if (start >= l && end <= r) {
      return Tree[n];
    } else if (r < start || l > end) {
      return 0;
    } else {
      int m = (start + end) / 2;
      int p1 = query(n * 2, start, m, l, r);
      int p2 = query(n * 2 + 1, m + 1, end, l, r);
      return p1 + p2;
    }
  }

  int sumRange(int i, int j) { return query(1, 1, N, i + 1, j + 1); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */