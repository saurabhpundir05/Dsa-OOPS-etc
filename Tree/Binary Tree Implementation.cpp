//Binary Tree Implementation(build,traversal(in, pre, post and level order))
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=right=NULL;
    }
};
//build binary tree
//Tc-O(n) Sc-O(n) 
static int idx=-1;
node *buildBinaryTree(vector<int> preorder){
    idx++;
    if(preorder[idx]==-1){
        return NULL;
    }
    node* root=new node(preorder[idx]);
    root->left=buildBinaryTree(preorder); //left
    root->right=buildBinaryTree(preorder); //right
    return root;
}
//pre-order traversal
//Tc-O(n) Sc-O(logn) O(n) 
void preOrder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
//in-order traversal
//Tc-O(n) Sc-O(logn) O(n) 
void inOrder(node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
//post-order traversal
//Tc-O(n) Sc-O(logn) O(n) 
void postOrder(node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
//level-order traversal
//Tc-O(n) Sc-O(n) 
void levelOrder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        node* curr=q.front();
        q.pop();
        if(curr==NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else{
                break;
            }
        }
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;
}
//Drivers Code
int main(){
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node* root=buildBinaryTree(preorder);
    cout<<"pre-order traversal"<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"in-order traversal"<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"post-order traversal"<<endl;
    postOrder(root);
    cout<<endl;
    cout<<"level-order traversal"<<endl;
    levelOrder(root);
    return 0;
}
//Output
// pre-order traversal
// 1 2 3 4 5 
// in-order traversal
// 2 1 4 3 5 
// post-order traversal
// 2 4 5 3 1 
// level-order traversal
// 1 
// 2 3 
// 4 5 