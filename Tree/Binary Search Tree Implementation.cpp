//Binary Search Tree Implementation (build,traversal(in, pre, post and level order))
//Seaching and Deletion of node
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
//Inserting node into BST
//Tc-O(logn) O(n) Sc-O(logn) O(n)
node* insert(node* root,int val){
    if(root==NULL){
        return new node(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);  
    }
    return root;
}
//Building BST
//Tc-O(logn) O(n2) Sc-O(n)
node* buildBinarysearchTree(vector<int> arr){
    node* root=NULL;
    for(int val:arr){
        root=insert(root,val);
    }
    return root;
}
//In-order Traversal
//Tc-O(n) Sc-O(logn) O(n) 
void inOrder(node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
//Pre-order Traversal
//Tc-O(n) Sc-O(logn) O(n) 
void preOrder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
//Post-order Traversal
//Tc-O(n) Sc-O(logn) O(n) 
void postOrder(node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
//Level-order Traversal
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
//Searching in BST
//Tc-O(height)
bool searchBst(node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    else if(key<root->data){
        return searchBst(root->left,key);
    }
    else{
        return searchBst(root->right,key);
    }
}
//Finding inorder successor
//Tc-O(logn) O(n) Sc-O(1)
node* getInorderSuccessor(node* root){
    while(root!=NULL && root->left!=NULL){
        root=root->left;
    }
    return root;
}
//Deleting a node from BST
//Tc-O(logn) O(n) Sc-O(logn) O(n)
node* delNode(node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key<root->data){
        root->left=delNode(root->left,key);
    }
    else if(key>root->data){
        root->right=delNode(root->right,key);
    }
    else{
        if(root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            node* is=getInorderSuccessor(root->right);
            root->data=is->data;
            root->right=delNode(root->right,is->data);

        }
    }
    return root;
}
//Drivers Code
int main(){
    vector<int> arr={3,2,1,5,6,4};
    node* root=buildBinarysearchTree(arr);
    cout<<"In-order Traversal"<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"Post-order Traversal"<<endl;
    postOrder(root);
    cout<<endl;
    cout<<"Level-order Traversal"<<endl;
    levelOrder(root);
    cout<<"Element search "<<searchBst(root,3)<<endl;
    cout<<"Before Delete"<<endl;
    inOrder(root);
    cout<<endl;
    delNode(root,5);
    cout<<"After Delete"<<endl;
    inOrder(root);
    cout<<endl;
    return 0;
}
//Output
// In-order Traversal
// 1 2 3 4 5 6 
// Post-order Traversal
// 1 2 4 6 5 3 
// Level-order Traversal
// 3 
// 2 5 
// 1 4 6 
// Element search 1
// Before Delete
// 1 2 3 4 5 6 
// After Delete
// 1 2 3 4 6 
