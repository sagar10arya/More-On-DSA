#include <bits/stdc++.h>
using namespace std;
/*
Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.
*/

class Solution {
    int countNodes(Node* root){
        if(root == NULL) return 0;
        
        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }
    
    bool isCBT(Node* root, int index, int count){
        if(root == NULL) return true;
        
        if(index >= count) return false;
        else{
            bool left = isCBT(root->left, 2*index + 1, count);
            bool right = isCBT(root->right, 2*index + 2, count);
            
            return left && right;
        }
    }
    
    bool isMaxOrder(Node* root){
        // leaff Node
        if(root->left == NULL && root->right == NULL) return true;
        
        // only left child exists
        if(root->right == NULL) return (root->data > root->left->data);
        
        else {
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            
            if(left && right && (root->data > root->left->data && root->data > root->right->data) ) return true;
            return false;
        }
        
    }
    
  public:
    bool isHeap(struct Node* tree) {
        int index  = 0;
        int totalCount = countNodes(tree);
        
        if(isCBT(tree, index, totalCount) && isMaxOrder(tree))
            return true;
        else return false;
    }
};