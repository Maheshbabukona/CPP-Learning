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
        return buildTree(preorder, idx);
    }
private:
    node* buildTree(vector<int> & preorder, int & idx){
        idx++;
        if(preorder[idx]==-1) return NULL;

        node* root = new node(preorder[idx]);
        root->left = buildTree(preorder,idx);
        root->right = buildTree(preorder,idx);

        return root;
    }
};
// two trees are identical if they are same structurally and value wise. So we compare left subtree, right subtree and then the root node.
class Solution{
public:
    bool isSameTree(node* p, node* q){
        if(p==NULL || q==NULL) return p==q; // true only if both are true, false otherwise

        bool isleftsame = isSameTree(p->left, q->left);
        bool isrightsame = isSameTree(p->right, q->right);

        return isleftsame && isrightsame && (p->data == q->data);
    }
};

int main(){
    vector<int> p_preorder = {1,2,-1,-1,3,-1,-1};
    vector<int> q_preorder = {1,2,-1,3,-1,-1,-1};

    Tree t;
    node* p = t.build(p_preorder);
    node* q = t.build(q_preorder);

    Solution S;
    cout << (S.isSameTree(p,q) ? "Yes" : "No");
}