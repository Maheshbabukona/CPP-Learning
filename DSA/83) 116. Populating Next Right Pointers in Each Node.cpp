#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node* next;

    node(int val){
        data = val;
        left= right = next = NULL;
    }
};

class BTree{
    node* buildTree(vector<int> &preorder, int &idx){
        idx++;
        if(preorder[idx]==-1) return NULL;

        node* root = new node(preorder[idx]);
        root->left = buildTree(preorder, idx);
        root->right = buildTree(preorder, idx);

        return root;
    }
public:
    node* build(vector<int> & preorder){
        int idx = -1;
        return buildTree(preorder, idx);
    }
};
// Goal - insert next pointer -- next pointer is the node which laterally next on the same level -- same as level order traversal.
// traverse on level order.. track prev and cur.. if prev is not null point the prev->next to cur.
class Solution{
public:
    node* connect(node* root) {
        if(root==NULL) return root;

        queue<node*> q;
        node* prev=NULL;
        q.push(root);
        q.push(NULL);

        while(q.size()>0){
            node* cur = q.front();
            q.pop();

            if(cur==NULL){
                if(q.size()==0) break;

                q.push(NULL);
            }
            else{
                if(cur->left!=NULL) q.push(cur->left);
                if(cur->right!=NULL) q.push(cur->right);

                if(prev!=NULL) prev->next = cur;
            }
            prev = cur;
        }
        return root;
    }
};

int main(){
    vector<int> preorder = {1,2,3,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};
    BTree T;
    node* root = T.build(preorder);

    Solution S;
    S.connect(root);

    cout << root->left->data << "->" << root->left->next->data;
}