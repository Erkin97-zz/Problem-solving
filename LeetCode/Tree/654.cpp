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
  TreeNode* constructTree(vector<int>& nums, int l, int r) {
    if (l >= r) {
      return NULL;
    }
    int max_index, max = -1;
    for (int i = l; i < r; i++) {
      if (nums[i] > max) {
        max = nums[i];
        max_index = i;
      }
    }
    TreeNode* node = new TreeNode(nums[max_index]);
    node->left = constructTree(nums, l, max_index);
    node->right = constructTree(nums, max_index + 1, r);
    return node;
  }
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return constructTree(nums, 0, nums.size());
  }
};