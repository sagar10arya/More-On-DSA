#include<bits/stdc++.h>
using namespace std;

/*
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
*/

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        
        vector<int> ans;
        
        if(root == NULL)
        {
            return ans;
        }
            
        map<int,int> topNode;
        queue<pair<Node*, int> > q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
        
            topNode[hd] = frontNode -> data;
            
            if(frontNode->left)
                q.push(make_pair(frontNode->left, hd-1));
                
            if(frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
        }
        
        for(auto i:topNode){
            ans.push_back(i.second);
        }
        
        return ans;
    }
    
};