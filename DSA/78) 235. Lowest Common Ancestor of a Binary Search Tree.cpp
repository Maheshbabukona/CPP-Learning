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
        left=right = NULL;
    }
};

class BST{
    node* insert(node* root, int val){
        if(root==NULL) return new node(val);

        if(root->data>val){
            root->left =  insert(root->left,val);
        }
        else root->right =  insert(root->right,val);
        
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
WKT == lowest common ancestor is the closest occuring parent.. as we traverse from down to up.

But as this is BST -- we can identify the parent node based on order.
1) if p->val and q->val < root->val then p and q exist on left side.. so does ancestor
2) else if p->val and q->val > root->val then p and q exist on right side -- so does ancestor
3) else --> they are on either sides or one is on either side and other is itself -- this case root is the closest common ancestor
*/
class Solution{
public:
    node* lowestCommonAncestor(node* root, node* p, node* q){
        if(root==NULL) return NULL;

        if(root->data>p->data && root->data > q->data) return lowestCommonAncestor(root->left,p,q);
        else if(root->data<p->data && root->data < q->data) return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};

int main(){
    vector<int> arr = {6,2,8,0,4,7,9,3,5};
    BST bst;
    node* root = bst.buildBST(arr);
    node* p = root->right;
    node* q = root->right->left;
    
    Solution S;
    cout << "The common ancestor for "<< p->data << " & "<<q->data << " is " << S.lowestCommonAncestor(root,p,q)->data;
}