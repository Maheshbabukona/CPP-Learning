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
/*
given its a cbt -- so we assume every parent is having ateast 2 nodes except for starting and ending nodes. 
So now.. we got to assume the nodes which are not present and add them up too
utilizing cbt index -- consider it a vector
As per cbt index for any parent node... its child nodes left is stored at index -- 2*(idxof parent)+1 and right is stored at index -- 2*(index of parent)+2

now how do we utilize this.. we are aware of starting index and ending index of current level -- so width at that level -- endidx-stidx+1;

Instead of popping one after other as in level order .. we pop in level by level -- so additional for loop to add every child of parent in cur level and remove the parents.

*/
class Solution{
public:
    int widthOfBinaryTree(node* root) {
        queue<pair<node*, unsigned long long>> cbtq;
        unsigned long long maxwidth =0;
        cbtq.push({root,0});

        while(cbtq.size()>0){
            int curlevsize = cbtq.size();
            unsigned long long stIdx = cbtq.front().second;
            unsigned long long endIdx = cbtq.back().second;

            maxwidth = max(maxwidth, endIdx-stIdx+1);

            for(int i=0;i<curlevsize;i++){
                auto cur = cbtq.front();
                cbtq.pop();

                if(cur.first->left){
                    cbtq.push({cur.first->left, cur.second*2+1});
                }
                if(cur.first->right){
                    cbtq.push({cur.first->right, cur.second*2+2});
                }
            }    
        }
        return maxwidth;
    }
};

int main(){
    vector<int> preorder = {1,3,5,-1,-1,3,-1,-1,2,-1,9,-1,-1};
    BTree T;
    node* root = T.build(preorder);
    Solution S;
    cout << "Max width of tree is: "<< S.widthOfBinaryTree(root);
}