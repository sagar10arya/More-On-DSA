#include<bits/stdc++.h>
using namespace std;


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

/*  Time Complexity --> O(N)     */
class Solution {
  public:
    
    // Function to return the diameter of a Binary Tree.
    pair<int,int> diameterFast(Node* root){
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = left.second;
        int op3 = left.second + right.second + 1;
        
        pair<int,int> ans;
        
        ans.first = max(op1, max(op2,op3));
        ans.second = max(left.second, right.second) + 1;
        
        return ans;
    }
    
    
    int diameter(Node* root) {
        
        return diameterFast(root).first;
    }
};


/*
Time complexity --> O(n^2);
class Solution {
    private:
    int height(struct Node* node){
        if(node == NULL) return 0;
        
        int left = height(node->left);
        int right = height(node->right);
        
        int ans = max(left,right) + 1;
        
        return ans;
    }
  public:
    
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(root == NULL) return 0;
        
        int left = diameter(root->left);
        int right = diameter(root->right);
        int combo = height(root->left) + 1 + height(root->right);
        
        int ans = max(left, max(right,combo));
        
        return ans;
    }
};
*/