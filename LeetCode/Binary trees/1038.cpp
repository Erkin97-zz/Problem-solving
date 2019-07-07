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
  int greater_sum(TreeNode* root, int par_sum) {
    int sum = root->val;
    bool f = true;
    if (root->right != NULL) {
      if (root->right->val == root->val) {
        sum = greater_sum(root->right, sum + par_sum);
      } else {
        sum += greater_sum(root->right, par_sum);
      }
      f = false;
    }
    if (f) sum += par_sum;
    root->val = sum;
    if (root->left != NULL) {
      return greater_sum(root->left, sum);
    }
    return sum;
  }
  TreeNode* bstToGst(TreeNode* root) {
    greater_sum(root, 0);
    return root;
  }
};