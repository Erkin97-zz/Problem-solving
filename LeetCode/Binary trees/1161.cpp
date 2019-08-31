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
  int maxLevelSum(TreeNode* root) {
    vector<TreeNode*> nodes;
    nodes.push_back(root);
    int maxi = -1, maxi_level;
    int level = 1;
    while (!nodes.empty()) {
      int sum = 0;
      vector<TreeNode*> children;
      for (int i = 0; i < nodes.size(); i++) {
        TreeNode* node = nodes[i];
        sum += node->val;
        if (node->left != NULL) {
          children.push_back(node->left);
        }
        if (node->right != NULL) {
          children.push_back(node->right);
        }
      }
      if (sum > maxi) {
        maxi = sum;
        maxi_level = level;
      }
      level++;
      nodes = children;
    }
    return maxi_level;
  }
};