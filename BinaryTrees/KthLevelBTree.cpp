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

class Tree{
public:
    node* build(vector<int> &preorder){
        int idx = -1;
        return buildTree(preorder,idx);
    }

private:
        node* buildTree(vector<int> &preorder, int &idx){
        idx++;
        if(preorder[idx]==-1) return NULL;

        node* root = new node(preorder[idx]);
        root->left = buildTree(preorder, idx);
        root->right = buildTree(preorder, idx);
        return root;
    }

};
/*
since root is considered as 1st level to reach kth level .. we reduce k for every level until we reach 1.

recursively for each side print all the elements where k is 1 i.e required level.
*/
class Solution{
public:
    int sum=0;
    void Klevel(node* root, int k){
        if(root==NULL) return;

        if(k==1){
            cout << root->data << " ";
            sum+=root->data;
        }

        Klevel(root->left,k-1);
        Klevel(root->right,k-1);
    }
};

int main(){
    vector<int> preorder = {1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};
    Tree T;
    node* root = T.build(preorder);

    Solution S;
    int K=3;
    cout << "Elements at "<< K<<"th level are: ";
    S.Klevel(root,K);
    cout << " with the sum "<< S.sum;
}