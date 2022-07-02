/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>a;
        if(root==NULL){
            return a;
        }
        stack<TreeNode*>s1;
        stack<TreeNode*>s;
        TreeNode* node=root;
        s.push(root);
        while(!s.empty()){
            root=s.top();
            s.pop();
            s1.push(root);
            if(root->left!=NULL){
                s.push(root->left);
            }
            if(root->right!=NULL){
                s.push(root->right);   
            }
        }
        while(!s1.empty()){
            a.push_back(s1.top()->val);
            s1.pop();
        }
        return a;
    }
};
/////////////////////////////////////////////////
vector < int > postOrderTrav(node * cur) {

  vector < int > postOrder;
  if (cur == NULL) return postOrder;

  stack < node * > st;
  while (cur != NULL || !st.empty()) {

    if (cur != NULL) {
      st.push(cur);
      cur = cur -> left;
    } else {
      node * temp = st.top() -> right;
      if (temp == NULL) {
        temp = st.top();
        st.pop();
        postOrder.push_back(temp -> data);
        while (!st.empty() && temp == st.top() -> right) {
          temp = st.top();
          st.pop();
          postOrder.push_back(temp -> data);
        }
      } else cur = temp;
    }
  }
  return postOrder;

}