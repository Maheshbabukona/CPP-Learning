#include <iostream>
#include <vector>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = right = NULL;
    }
};

class BST{
private:
    node* insert(node* root, int val){
        if(root==NULL){
            return new node(val);
        }
        if(val<root->data){
            root->left = insert(root->left, val);
        }
        else{
            root->right = insert(root->right, val);
        }
        return root;
    }
    node* getIS(node* root){
        while(root->left!=NULL){
            root = root->left;
        }
        return root;
    }
public:
    node* buildBST(vector<int> arr){
        node* root = NULL;
        for(int val: arr){
            root = insert(root,val);
        }
        return root;
    }

    void inorder(node* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout << root->data << "->";
        inorder(root->right);
    }
    bool search(node* root, int key){
        if(root==NULL) return false;
        if(root->data == key) return true;
        else if(key<root->data) return search(root->left,key);
        else return search(root->right,key);
    }

    node* delNode(node*root, int key){
        // search for the key node
        if (root==NULL) return NULL;
        if(key<root->data){
            root->left = delNode(root->left,key);
        }
        else if(key>root->data){
            root->right = delNode(root->right,key);
        }
        else{
           // case 1: 0 children;
           if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
           }
           else if(root->left==NULL){
            node* temp = root->right;
            delete root;
            return temp;
           }
           else if(root->right==NULL){
            node* temp = root->left;
            delete root;
            return temp;
           }
           else{
            node* IS = getIS(root->right);
            root->data = IS->data;
            root->right = delNode(root->right,IS->data);
           } 
        }
        return root;
    }
};

int main(){
    vector<int> arr = {3,2,1,5,6,4};
    BST bst;
    node* root = bst.buildBST(arr);
    bst.inorder(root);
    cout << "\nSearching if 10 exists in BST:";
    cout << ((bst.search(root,10)) ? "True": "False");
    bst.delNode(root,5);
    cout <<"\nAfter deleting 5\n";
    bst.inorder(root);
}