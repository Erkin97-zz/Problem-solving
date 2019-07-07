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
  int rangeSumBST(TreeNode* root, int L, int R) {
    if (root == NULL) return 0;
    stack<TreeNode*> st;
    st.push(root);
    int sum = 0, val;
    TreeNode* node;
    while (!st.empty()) {
      node = st.top();
      st.pop();
      if (node != NULL) {
        val = node->val;
        if (val >= L && val <= R) {
          sum += node->val;
        }
        if (val > L) {
          st.push(node->left);
        }
        if (val < R) {
          st.push(node->right);
        }
      }
    }
    return sum;
  }
};