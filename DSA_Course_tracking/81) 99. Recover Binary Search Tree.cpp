#include <iostream>
#include <vector>
#include <queue>
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
            root->left = insert(root->left,val);
        }
        else{
            root->right = insert(root->right, val);
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

    void levelTraversal(node* root){
        queue<node*> q;
        q.push(root);
        q.push(NULL);
        while(q.size()>0){
            node* cur = q.front();
            q.pop();

            if(cur==NULL){
                if(!q.empty()){
                    cout << endl;
                    q.push(NULL);
                    continue;
                }
                else{
                    break;
                }
            }

            cout << cur->data << " ";
            if(cur->left!=NULL) q.push(cur->left);
            if(cur->right!=NULL) q.push(cur->right);            
        }
    }
};
/*
The tree has 2 such nodes which are swapped making it a non binary search tree.. it means somewhere in the tree.. the prev>root and root<prev.
In these cases if we consider first and second 2 vars... There can be 2 pairs of first and sec.. 
But on first occurance.. its anamoly because prev> root.. prev is anamoly and first= prev
on second occurance.. its anamoly because root<prev.. root is anamoly and  sec = root
*/
class Solution{
    node* prev=NULL;
    node* first = NULL;
    node* sec = NULL;
    void inorder(node* root){
        if(root==NULL) return;

        inorder(root->left);
        if(prev!=NULL && root->data<prev->data){
            if(first==NULL){
                first = prev;
            }
            sec = root;
        }
        prev = root;
        inorder(root->right);
    }  
public:
    void recoverorder(node* root){
        inorder(root);

        int temp = first->data;
        first->data = sec->data;
        sec->data = temp;
    }
};

int main(){
    vector<int> arr = {6,3,1,4,8,9};
    BST bst;
    node* root = bst.buildBST(arr);
    // swapping 
    int temp = root->left->right->data;
    root->left->right->data = root->right->data;
    root->right->data = temp;
    cout << "Swapped Non BST:\n";
    bst.levelTraversal(root);

    Solution S;
    S.recoverorder(root);
    cout << "\nAfter recovery:\n";
    bst.levelTraversal(root);

}