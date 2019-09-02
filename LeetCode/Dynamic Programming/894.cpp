/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  vector<TreeNode*> allPossibleFBT(int N) {
    vector<vector<TreeNode*> > dm(N + 1);
    if (N % 2 == 0) {
      return dm[0];
    }
    dm[1].push_back(new TreeNode(0));
    for (int i = 3; i <= N; i += 2) {
      for (int x = 1; x <= i - 1; x += 2) {
        int y = i - 1 - x;
        for (int j = 0; j < dm[x].size(); j++) {
          TreeNode* left = dm[x][j];
          for (int k = 0; k < dm[y].size(); k++) {
            TreeNode* right = dm[y][k];
            TreeNode* new_tree = new TreeNode(0);
            new_tree->left = left;
            new_tree->right = right;
            dm[i].push_back(new_tree);
          }
        }
      }
    }
    return dm[N];
  }
};