#include<bits/stdc++.h>
using namespace std;
/*
Input:
        1
      /   \
     2     3
    / \   /  \
   4   5 6    7
Output:
1 3 2 4 5 6 7
*/
/*Structure of the node of the binary tree is as */
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> result;
    	if(root == NULL) return result;
    	
    	queue<Node*> q;
    	q.push(root);
    	
    	bool leftToRight = true;
    	
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int> ans(size);
    	    
    	    // Level Process
    	    for(int i=0; i<size; i++){
    	        Node *frontNode = q.front();
    	        q.pop();
    	        
    	        // Normal insert or reverse insert
    	        int index = leftToRight ? i : size - i -1;
    	        ans[index] = frontNode->data;
    	        
    	        if(frontNode->left){
    	            q.push(frontNode->left);
    	        }
    	        if(frontNode->right){
    	            q.push(frontNode->right);
    	        }
    	        
    	        //Direction change krni hai
    	        leftToRight = !leftToRight;
    	    }
    	}
    }
};