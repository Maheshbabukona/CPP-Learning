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

class BTree{
public:
    node* build(vector<int> &preorder){
        int idx = -1;
        return buildTree(preorder,idx);
    }
private:
    node* buildTree(vector<int> &preorder, int &idx){
        idx++;
        if (preorder[idx] == -1) return NULL;

        node* root = new node(preorder[idx]);
        root->left = buildTree(preorder, idx);
        root->right = buildTree(preorder, idx);

        return root;
    }
};

/*
So goal --> to flatten the tree and connect everything in preorder in the right as a linked list.. so LL->next == T->right.
So instead.. of top to bottom -- lets connect in reverse --> flatten the right tree -> connect it to flattened left tree and then connect the root.
So to track where to connect we utilize nextRight node --> as we are following right->left->root approach -- the root of subtrees becomes the nextright -- which is the connecting node.
*/
class Solution{
public:
    node* nextRight = NULL;

    void flatten(node* root){
        if(root==NULL) return;

        flatten(root->right);
        flatten(root->left);
        root->left = NULL;
        root->right = nextRight;
        nextRight = root;
    }
};

int main(){
    vector<int> preorder = {1,2,3,-1,-1,4,-1,-1,5,-1,6,-1,-1};
    BTree T;
    node* root = T.build(preorder);
    Solution S;
    S.flatten(root);

    while(root!=NULL){
        cout << root->data << "->";
        root=root->right;
    }
    cout << "NULL";
}