#include<bits/stdc++.h>
using namespace std;
/*
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 
*/

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// Time complexity --> O(N)


class Solution{
    public:
    pair<bool,int> isBalancedFast(Node *root){
        if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
        }
        
        pair<int,int> left = isBalancedFast(root->left);
        pair<int,int> right = isBalancedFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs(left.second - right.second) <=1;
        
        pair<bool,int> ans;
        ans.second = max(left.second,right.second) + 1;
        
        if(leftAns && rightAns && diff){ 
            ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        
        return isBalancedFast(root).first;
    }
};


/*
// Time complexity --> O(N^2);
class Solution{
    private:
    int height(struct Node* node){
        // base case
        if(node == NULL) return 0;
        
        int left = height(node->left);
        int right = height(node->right);
        int ans = max(left,right) + 1;
        
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Base Case
        if(root == NULL){
            return true;
        }
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        bool diff = abs(height(root->left) - height(root->right)) <= 1;
        
        if(left && right && diff) return 1;
        else return false;
    }
}
*/