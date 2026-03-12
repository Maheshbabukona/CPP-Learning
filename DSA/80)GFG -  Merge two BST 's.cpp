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

class BST{
    node* insert(node* root, int val){
        if(root==NULL) return new node(val);

        if(root->data > val){
            root->left = insert(root->left, val);
        }
        else if(root->data < val){
            root->right = insert(root->right, val);
        }

        return root;
    }
public:
    node* buildBST(vector<int> arr){
        node* root = NULL;
        for(int val: arr){
            root = insert(root,val);
        }

        return root;
    }
};
/*
we have 2 bsts root1, root2 .. merge them and return the inorder of the merged bst..

So we find the inorder of both bsts.. merge the inorder arrays and return it. which will be the final inorder array 
-- its more like merge 2 sorted lists after inorders were found for both bsts.
*/
class Solution{
    void inorder(node* root, vector<int> &arr){
        vector<int> inorder_arr;
        if(root==NULL) return;

        inorder(root->left, arr);
        inorder_arr.push_back(root->data);
        inorder(root->right, arr);
    }
    void merge2sortedarrs(vector<int> arr1, vector<int> arr2, vector<int> &mergedarr){
        int i=0, j=0;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]<arr2[j]){
                mergedarr.push_back(arr1[i++]);
            }
            else{
                mergedarr.push_back(arr2[j++]);
            }
        }
        while(i<arr1.size()){
            mergedarr.push_back(arr1[i++]);
        }
        while(j<arr2.size()){
            mergedarr.push_back(arr2[j++]);
        }
    }
public:
    vector<int> merge(node *root1, node *root2) {
        vector<int> arr1, arr2;
        inorder(root1,arr1);
        inorder(root2,arr2);

        vector<int> mergedarr;

        merge2sortedarrs(arr1,arr2,mergedarr);
        return mergedarr;
    }
};

int main(){
    vector<int> nums1 = {8, 2, 10, 1};
    vector<int> nums2 = {5, 3, 0};

    BST bst;
    node* root1 = bst.buildBST(nums1);
    node* root2 = bst.buildBST(nums2);
    Solution S;
    vector<int> res = S.merge(root1,root2);
    cout << "Inorder of merged trees:\n";
    for(int val: res){
        cout << val << " ";
    }
}