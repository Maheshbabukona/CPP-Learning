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

class Tree{

public:
    node* build(vector<int> & preorder){
        int idx = -1;
        buildTree(preorder, idx);
    }
private:
    node* buildTree(vector<int> &preorder, int & idx){
        idx++;
        if(preorder[idx]==-1) return NULL;

        node* root = new node(preorder[idx]);
        root->left = buildTree(preorder, idx);
        root->right = buildTree(preorder, idx);
        return root;
    }
};