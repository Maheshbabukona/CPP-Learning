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

    void preorder_traversal(node* root){
        if(root==NULL){
            cout << " -1 ";
            return;
        }
        cout << root->data << " ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
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

class Solution{
public:
/*
string path --> root
for left paht+"->"+its->data
for right path+"->"+its->data
stop at leaf node and push back the path to ans
*/
    void helper(node* root, string path, vector<string> &ans){
        if(root->left==NULL && root->right==NULL){
            ans.push_back(path);
            return;
        }

        if(root->left){
            helper(root->left,path+"->"+to_string(root->left->data),ans);
        }
        if(root->right){
            helper(root->right, path+"->"+to_string(root->right->data), ans);
        }
    }
    vector<string> binaryTreePaths(node* root){
        vector<string> ans;
        string path = to_string(root->data);
        helper(root,path, ans);
        return ans;
    }
};

int main(){
    vector<int> preorder = {1,2,-1,-1, 3,4,-1,-1,-1};
    BTree T;
    node* root = T.build(preorder);
    Solution S;
    vector<string> res = S.binaryTreePaths(root);
    cout << "[ ";
    cout << res[0] << " , ";
    cout << res[1] << " ]";
}