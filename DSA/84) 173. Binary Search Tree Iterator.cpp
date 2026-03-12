#include <iostream>
#include <vector>
#include <stack>
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
    node* insert(node* root, int val){
        if (root==NULL) return new node(val);

        if(val<root->data){
            root->left = insert(root->left, val);
        }    
        else{
            root->right = insert(root->right, val);
        }
        return root;

    }

public:
    node* buildBST(vector<int> &arr){
        node* root = NULL;
        for(int val: arr){
            root = insert(root,val);
        }
        return root;
    }
};

class BSTIterator{
public:
    stack<node*> s;
    void storeleftmost(node* root){
        while(root!=NULL){
            s.push(root);
            root= root->left; // with this all left nodes are in stack
        }
    }
    BSTIterator(node* root){
        storeleftmost(root);
    }

    int next(node* root){
        node* ans = s.top(); // with this root is in the stack
        s.pop();
        storeleftmost(root->right); // right+ rights left wing.. in the stack.

        return ans->data;
    }

    bool hasnext(){
        return s.size()>0;
    }
};

int main(){
    vector<int> arr = {7,3,15,9,20};
    BST bst;
    node* root = bst.buildBST(arr);
    
    BSTIterator iterator(root);
    cout << "Next as per inorder" << iterator.next(root) << endl;
    cout << "Does next element exist ? " << iterator.hasnext();
}
