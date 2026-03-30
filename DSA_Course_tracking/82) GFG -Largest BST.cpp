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
/*
At root we should be receiving three things.. min,max, and max size. there cant be any datatype to hold three -- so we create a class through which we can access those.

The root is valid only if root->data>left max and right min.. only then we update with-->
once we achieve this.. we then consider current also .. so update curmin, curmax, cursize.

if it isnt valid root -- then we should make it impossible to consider for updaing min and max but keep track of its valid subtrees size.
so we return (-inf, +inf, max(leftsz,rightsz)) -- this way min(-inf,any) -- is -inf.. so any root checking this cannot be valid. 
*/
class Info{
public:
    int min,max,sz;

    Info(int mi, int mx, int size){
        min = mi;
        max = mx;
        sz= size;
    }
};
class Solution{
public:
    Info helper(node* root){
        if(root==NULL) return Info(INT32_MAX,INT32_MIN,0); // why null nodes values should be able to replaced by any..

        Info left = helper(root->left);
        Info right = helper(root->right);

        if(root->data>left.max && root->data <  right.min){// valid root.
            int curmin = min(root->data, left.min);
            int curmax = max(root->data,right.max);
            int cursz = left.sz+right.sz+1;

            return Info(curmin,curmax,cursz);
        }

        return Info(INT32_MIN,INT32_MAX, max(left.sz,right.sz));
    }

    int largestBST(node* root){
        Info info = helper(root);
        return info.sz;
    }
};

int main(){
    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(15);
    root->left->left = new node(1);
    root->left->right = new node(8);
    root->right->right = new node(7);

    Solution S;
    cout << "Size of largest BST: "<< S.largestBST(root);
}