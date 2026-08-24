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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==NULL){
            return ans;

        }
        q.push(root);
        while(!q.empty()){
            vector<int>arr;
            int n=q.size();
            for(int i=0;i<n;i++){
            TreeNode *ne=q.front();
            q.pop();
            if(ne->left!=NULL){
                q.push(ne->left);
            }
            if(ne->right!=NULL){
                q.push(ne->left);
            }
            arr.push_back(ne->val);
            }



            ans.push_back(arr);

        }
        return ans;
        

        
    }
};
