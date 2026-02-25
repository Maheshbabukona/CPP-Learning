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

static int idx=-1;
node* buildTree(vector<int> preorder){
    idx++;
    if(preorder[idx]==-1){ // leaf node -- point to NULL.
        return NULL;
    }

    node* root = new node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void preorder_traversal(node* root){
    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(node* root){
    if(root==NULL){
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

void postorder_traversal(node* root){
    if(root==NULL){
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
}

void levelorder_traversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        node* cur = q.front();
        q.pop();

    if(cur==NULL){
        if(!q.empty()){ // q still has few elements from the next level -> so print them in next line.. and continue
            cout << endl;
            q.push(NULL);
            continue;
        }
        else{ // last NULL.. no next level.. break the while loop.
            break;
        }
    }
        cout << cur->data<< " ";
        if(cur->left!=NULL){
            q.push(cur->left);
        }
        if(cur->right!=NULL){
            q.push(cur->right);
        }
    }
    
}

int main(){
    vector<int> preoder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node* root = buildTree(preoder);
    cout << "Preorder Traversal:\n";
    preorder_traversal(root);
    cout << "\nInorder Traversal:\n";
    inorder_traversal(root);
    cout << "\nPostorder Traversal:\n";
    postorder_traversal(root);

    cout << "\nLevelOrder Traversal:\n";
    levelorder_traversal(root);

}