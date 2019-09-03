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
 private:
  int dfs_count(TreeNode* node) {
    int sum = 0;
    if (node->left != NULL) {
      sum += dfs_count(node->left);
      node->val += (node->left->val - 1);
    }
    if (node->right != NULL) {
      sum += dfs_count(node->right);
      node->val += (node->right->val - 1);
    }
    sum += abs(node->val - 1);
    return sum;
  }

 public:
  int distributeCoins(TreeNode* root) { return dfs_count(root); }
};