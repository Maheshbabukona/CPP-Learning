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
    node* insert(node* root, int val){
        if(root==NULL) return new node(val);
        
        if(val<root->data){
            root->left = insert(root->left, val);
        }
        else{
            root->right = insert(root->right,val);
        }
        return root;
    }
public:
    node* buildBST(vector<int> arr){
        node* root = NULL;
        for(int val: arr){
            root = insert(root, val);
        }
        return root;
    }                                                                                    
};

/*
case 1 - if the key < root->val so the key exists in left subtree.. then cur root becomes potential successor...
Case 2 - if the key > root->val so the key exits in the right subtree.. then cur root becomes the potential predecessor..
case 3 - if the key == root->val so we find the rightmost of left subtree which becomes predecessor and leftmost of right subtree which becomes successor
*/
class Solution{
    node* rigthmostinLeft(node* root){
        while(root->right!=NULL){
            root = root->right;
        }
        return root;
    }
    node* leftmostinRight(node* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
public:

    vector<node*> findPreSuc(node* root, int key){
        vector<node*> res;
        node* cur = root;
        node* pred = NULL;
        node* succ = NULL;

        while(cur!=NULL){if(key<cur->data){
            succ = cur;
            cur = cur->left;
        }
        else if(key>cur->data){
            pred = cur;
            cur = cur->right;
        }
        else{
            if(cur->left!=NULL){
                pred = rigthmostinLeft(cur->left);
            }            
            if(cur->right!=NULL){
                succ = leftmostinRight(cur->right);
            }
        }}
        res.push_back(pred);
        res.push_back(succ);

        return res;
    }
};

int main(){
    vector<int> arr = {50, 30, 70, 20, 40, 60, 80};
    int key = 65;
    BST bst;
    node* root = bst.buildBST(arr);
    Solution S;
    vector<node*> result = S.findPreSuc(root,key);

    cout << "Predecessor for "<< key << " is "<< result[0]->data << endl;
    cout << "Successor for "<< key << " is "<< result[1]->data;
}