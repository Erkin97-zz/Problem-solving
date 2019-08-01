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
  bool isUnivalTree(TreeNode* root) {
    int root_val = root->val;
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
      TreeNode* node = st.top();
      st.pop();
      if (node == NULL) continue;
      if (node->val != root_val) return false;
      st.push(node->left);
      st.push(node->right);
    }
    return true;
  }
};