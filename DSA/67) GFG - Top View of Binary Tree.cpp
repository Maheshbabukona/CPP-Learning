#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
        if(preorder[idx]==-1) return NULL;

        node* root = new node(preorder[idx]);
        root->left = buildTree(preorder,idx);
        root->right = buildTree(preorder,idx);

        return root;
    }
};

/*
we make slight modifications as we traverse levelwise
we store pair<node,horizontal distance> we can track horizontal distance.
we store nodes wrt to distance in a map as they come .. only the first instance. Map can cout >> order wise based on distance.
*/
class Solution{
public:

    vector<int> TopView(node* root){
        queue<pair<node*,int>> q; // (node, horizontal distance)
        map<int,int> m; // (horizontal distance, node->data)
        vector<int> res;
        if(root==NULL) return {};
        q.push({root,0});
        
        while(q.size()>0){
            node* cur = q.front().first;
            int curhd = q.front().second; // hd - horizontal distance
            q.pop();
            if(m.find(curhd)==m.end()){ // only insert if the distance based node doesnt exist
                m[curhd] = cur->data;
            }
            if(cur->left!=NULL){
                q.push({cur->left,curhd-1});
            }
            if(cur->right!=NULL){
                q.push({cur->right,curhd+1});
            }
        }

        for(auto it: m){
            res.push_back(it.second);
        }

        return res;

    }
};

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    BTree T;
    node* root = T.build(preorder);

    Solution S;
    vector<int> ans = S.TopView(root);

    for(int val: ans){
        cout << val << " ";
    }
}