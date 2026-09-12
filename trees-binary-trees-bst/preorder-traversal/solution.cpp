/* Structure of Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> preOrder(Node* root) {
        vector<int>arr;
        stack<Node*>st;
        st.push(root);
        while(!st.empty()){
            Node *no=st.top();
            st.pop();
            if(no->right!=NULL){
                st.push(no->right);
            }
            if(no->left!=NULL){
                st.push(no->left);
            }
            arr.push_back(no->data);
            
            
    }
    return arr;
    }
};
