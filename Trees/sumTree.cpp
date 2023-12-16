#include<bits/stdc++.h>
using namespace std;

/* Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.
An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.
*/

/*  Tree node  */
struct Node
{
    int data;
    Node* left, * right;
};

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    
    pair<bool,int> isSumTreeFast(Node* root){
        if(root == NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int> leftAns = isSumTreeFast(root->left);
        pair<bool,int> rightAns = isSumTreeFast(root->right);
        
        bool isleftSumTree = leftAns.first;
        bool isrightSumTree = rightAns.first;
        
        int leftSum = leftAns.second;
        int rightSum = rightAns.second;
        
        bool condn = root->data == leftSum + rightSum;
        
        pair<bool,int> ans;
        if(isleftSumTree && isrightSumTree && condn){
            ans.first = true;
            ans.second = root->data + leftSum + rightSum;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    
    bool isSumTree(Node* root)
    {
         return isSumTreeFast(root).first;
    }
};