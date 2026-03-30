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
Morris Inorder traversal -- uses connection modifications to traverse the tree with O(1) Space for larger trees.
As you know inorder printing order is left->root->right.
Before going to the root from completing the left we make a connection from lefts last node to root..
Now that connection is made from leftlast to root--> travel the left -- this way you can come back to root after leaf. as you come back remove the connection.. and then print the root.
*/
class Solution{
public:
    vector<int> MorrisInorder(node* root){
        vector<int> ans;
        node* cur = root;
        while(cur!=NULL){
        if(cur->left == NULL){ // No left exist .. print the root and go to right
            ans.push_back(cur->data);
            cur=cur->right;
        }
        else{
            // find the IP
            node* IP = cur->left; // Ip is last element of leftsubtree
            while(IP->right!=NULL && IP->right!=cur){ // till you reach last element -- thats not already connected.
                IP=IP->right;
            }
            if(IP->right==NULL){ // Ip connection is not made yet -- you reached the just previous element of root or cur
                IP->right = cur;
                cur=cur->left; // as connection is made move to left
            }
            else{ // connection is made
                IP->right=NULL; // change it back to null as you completed printing all left.
                ans.push_back(cur->data); // lefts done so print cur 
                cur = cur->right;
            }
        }}
        return ans;
    }
};

int main(){
    vector<int> preorder = {1,2,3,-1,4,-1,-1,-1,5,-1,-1};
    BTree T;
    node* root = T.build(preorder);
    Solution S;
    vector<int> res = S.MorrisInorder(root);
    for(int val : res){
        cout << val << " ";
    }
}