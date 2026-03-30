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
    int transformtosumtree(node* root){
        if(root==NULL) return 0;

        int cursum = root->data;
        int leftsum = transformtosumtree(root->left);
        int rightsum = transformtosumtree(root->right);

        root->data = cursum+leftsum+rightsum;

        return root->data;
    }
};

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    BTree T;
    node* root = T.build(preorder);
    cout << "Before transforming into Sum Tree\n";
    T.preorder_traversal(root);

    Solution S;
    int res = S.transformtosumtree(root);
    cout << "\nAfter Transforming into Sum Tree\nSum = "<< res << endl;
    cout << "Tree: \n";
    T.preorder_traversal(root);
}