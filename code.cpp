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
 
 
 
       1
   2       3
4    5   6   7
 */
class Solution {
public:
    int flag=0;
    void fxn(TreeNode* root ,  vector<TreeNode*>& v , set<int> &st ){
        if(root==NULL){
            return ;
        }
        
        fxn (root->left,v,st);
        fxn (root->right,v,st);
        if(root->left!=NULL && st.find(root->left->val)!=st.end()){
            TreeNode* p=root->left;
            if(root->left->left!=NULL)
            v.push_back(root->left->left);
            if(root->left->right!=NULL)
            v.push_back(root->left->right);
            root->left=NULL;
        }
        if(root->right!=NULL && st.find(root->right->val)!=st.end()){
            TreeNode* p=root->right;
            if(root->right->left!=NULL)
            v.push_back(root->right->left);
            if(root->right->right!=NULL)
            v.push_back(root->right->right);
            root->right=NULL;
        }
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& vm){
        set<int> st;
        for(int i=0;i<vm.size();i++){
            st.insert(vm[i]);
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> v,v3;
        while(!st.empty()){
            if(st.find(q.front()->val)!=st.end()){
                if(q.front()->left!=NULL)
                q.push(q.front()->left);
                if(q.front()->right!=NULL)
                    q.push(q.front()->right);
            }
            else{
                v3.push_back(q.front());
            }
            q.pop();
        }
        
        while(!q.empty()){
            v.push_back(q.front());
;            fxn(q.front(),v,st);
            q.pop();
        }
        // while(!q.empty()){
        //     TreeNode* ptr=q.front();
        //     if(ptr->left!=NULL){
        //         q.push(ptr->left);
        //         int val=q.front()->left->val;
        //         if(st.find(val)!=st.end()){
        //             if(ptr->left->left!=NULL){
        //             v.push_back(ptr->left->left);
        //             q.push(ptr->left->left);
        //             }
        //             if(ptr->left->right!=NULL){
        //             v.push_back(ptr->left->right);
        //             q.push(ptr->left->right);
        //             }
        //             q.front()->left=NULL;
        //         }
        //     }
        //     if(ptr->right!=NULL){
        //         q.push(ptr->right);
        //         int val=q.front()->right->val;
        //         if(st.find(val)!=st.end()){
        //             if(ptr->right->left!=NULL){
        //             v.push_back(ptr->right->left);
        //             q.push(ptr->right->left);
        //             }
        //             if(ptr->right->right!=NULL){
        //             v.push_back(ptr->right->right);
        //             q.push(ptr->right->right);
        //             }
        //             q.front()->right=NULL;
        //         }
        //     }
        //     q.pop();
        // }
        return v;
    }
};
