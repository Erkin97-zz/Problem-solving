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
  TreeNode* LSA;
  int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || LSA != NULL) {
      return 0;
    }
    int count = 0;
    if (root == p) {
      count++;
    }
    if (root == q) {
      count++;
    }
    count += dfs(root->left, p, q);
    count += dfs(root->right, p, q);
    if (count == 2) {
      LSA = root;
      count = 0;
    }
    return count;
  }
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    LSA = NULL;
    dfs(root, p, q);
    return LSA;
  }
};