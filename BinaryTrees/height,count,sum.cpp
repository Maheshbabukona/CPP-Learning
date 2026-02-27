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

class Solution{
public:
int height_tree(node* root){
    if(root==NULL) return 0;
    int left_tree = height_tree(root->left);
    int right_tree = height_tree(root->right);

    return max(left_tree,right_tree) + 1;
}

int count_nodes(node* root){
    if(root==NULL) return 0;
    int left_count = count_nodes(root->left);
    int right_count = count_nodes(root->right);

    return left_count+right_count+1;
}

int sum_nodes(node* root){
    if(root==NULL) return 0;
    int left_sum = sum_nodes(root->left);
    int right_sum = sum_nodes(root->right);

    return left_sum+right_sum+root->data;
}
};



int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1, 5,-1,-1};
    Tree t;
    Solution S;
    node* root = t.build(preorder);
    
    cout << "Height of the tree: " << S.height_tree(root) << endl;
    cout << "Total number of nodes: " << S.count_nodes(root) << endl;
    cout << "Sum of nodes: " << S.sum_nodes(root) << endl;
}