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

class BST{ // to build 2 arrays.
    node* insert(node* root, int val){
        if (root==NULL) return new node(val);

        if(root->data>val){
            root->left  = insert(root->left,val);
        }
        else{
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
derive inorder from 2 bsts. Merge the 2 bsts and then build the balanced bst from new inorder sequence
*/

class Solution{
    node* sortedarrayBST(vector<int> &arr, int st, int end){ // two build the new bst from new inorder
        if (st>end) return NULL;
        int mid = st+(end-st)/2;
        node* root = new node(arr[mid]);
        root->left = sortedarrayBST(arr,st,mid-1);
        root->right = sortedarrayBST(arr,mid+1,end);

        return root;
    }
    void inorder(node* root, vector<int> &arr){
        if(root==NULL) return;
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    vector<int> mergearr(vector<int> &arr1, vector<int> &arr2){
        vector<int> temp;
        int i=0,j=0;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]<arr2[j]){
                temp.push_back(arr1[i++]);
            }
            else{
                temp.push_back(arr2[j++]);
            }
        }
        while(i< arr1.size()){
            temp.push_back(arr1[i++]);
        }
        while(j< arr2.size()){
            temp.push_back(arr2[j++]);
        }
        return temp;
    }
public:
    node* Merge2BSTs(node* root1, node* root2){
        vector<int> arr1, arr2;
        inorder(root1,arr1);
        inorder(root2,arr2);
        vector<int> mergedarr = mergearr(arr1,arr2);
        return sortedarrayBST(mergedarr,0,mergedarr.size()-1);
    }
    void leveltraversal(node* root){
        queue<node*> q;
        q.push(root);
        q.push(NULL);
        while(q.size()>0){
            node* cur = q.front();
            q.pop();
            
            if(cur==NULL){
                if(!q.empty()){
                    cout << endl;
                    q.push(NULL);
                    continue;
                }
                else{
                    break;
                }
            }
            cout << cur->data << " ";
            if(cur->left!=NULL){
                q.push(cur->left);
            }
            if(cur->right!=NULL){
                q.push(cur->right);
            }
        }
    }
};

int main(){
    vector<int> nums1 = {8, 2, 10, 1};
    vector<int> nums2 = {5, 3, 0};
    BST bst;
    node* root1 = bst.buildBST(nums1);
    node* root2 = bst.buildBST(nums2);
    Solution S;
    cout << "Nums1 BST - before Merge:\n";
    S.leveltraversal(root1);
    cout << "\nNums2 BST - before Merge:\n";
    S.leveltraversal(root2);
    cout << "\nNew Tree after merging both trees:\n";
    node* mergedroot = S.Merge2BSTs(root1,root2);
    S.leveltraversal(mergedroot);
}