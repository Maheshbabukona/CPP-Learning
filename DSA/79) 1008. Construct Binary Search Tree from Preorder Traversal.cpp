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

class Solution{
    node* insert(node* root, int val){
        if(root==NULL) return new node(val);

        if(root->data>val){
            root->left = insert(root->left, val);
        }
        else{
            root->right = insert(root->right, val);
        }
        return root;
    }
public:
    node* bstFromPreorder(vector<int>& preorder) {
        node* root = NULL;
        for(int val: preorder){
            root = insert(root,val);
        }
        return root;
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
    vector<int> preorder = {8,5,1,7,10,12};
    Solution S;
    node* root = S.bstFromPreorder(preorder);
    cout << "The tree from preorder is:\n";
    S.leveltraversal(root);
}