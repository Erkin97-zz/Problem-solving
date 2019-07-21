/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
 public:
  vector<int> postorder(Node* root) {
    vector<int> postOrder;
    stack<Node*> st;
    st.push(root);
    Node* node;
    while (!st.empty()) {
      node = st.top();
      st.pop();
      if (node == NULL) continue;
      postOrder.insert(postOrder.begin(), node->val);

      for (int i = 0; i < node->children.size(); i++) {
        st.push(node->children[i]);
      }
    }
    return postOrder;
  }
};