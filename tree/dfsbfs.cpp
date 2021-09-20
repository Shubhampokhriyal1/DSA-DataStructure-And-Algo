#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    Node * left,*right;
    int data;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
class bfs{
public:
    void levelOrder(Node* root){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            if(q.front()->left!=NULL){
                q.push(q.front()->left);
            }
            cout<<q.front()->data<<" ";
            if(q.front()->right!=NULL){
                q.push(q.front()->right);
            }
            q.pop();
        }
    }
};
class dfs{
public:
void pre(Node *root){//root left right
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}
void inorder(Node * root){//left root right 
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node *root){//left right root
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
};
int main() {
    // creating a binarytree
    Node *root=new Node(1);
    root->right=new Node(3);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    dfs obj;
    obj.pre(root);
    cout<<endl;
    obj.inorder(root);
    cout<<endl;
    obj.postorder(root);
    bfs obj2;
    cout<<endl;
    obj2.levelOrder(root);
    return 0;
}