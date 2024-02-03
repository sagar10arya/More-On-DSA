// Construct Tree from Inorder & Preorder
/* 
Given 2 Arrays of Inorder and preorder traversal. The tree can contain duplicate elements. Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
*/


#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    void createMapping(int in[], map<int,int> &nodeToIndex, int n){
        for(int i=0; i<n; i++){
            nodeToIndex[in[i]] = i;
        }
    }
    
    Node* solve(int in[],int pre[], int &index,int inOrderStart, int inOrderEnd, int n,map<int,int> &nodeToIndex){
        // Base Case
        if(index >= n || inOrderStart > inOrderEnd) {
            return NULL;
        }
        // Create a root node for element
        int element = pre[index++];
        Node* root = new Node(element);
        // Find elements's index inorder
        int position = nodeToIndex[element];
        
        // recursive call
        root->left = solve(in,pre,index,inOrderStart, position-1, n,nodeToIndex);
        root->right = solve(in,pre,index,position+1,inOrderEnd, n,nodeToIndex);
        
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        map<int,int> nodeToIndex;
        // Creates Node to index map
        createMapping(in,nodeToIndex,n);
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n,nodeToIndex);
        return ans;
    }
};


#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    void createMapping(int in[], map<int,int> &nodeToIndex, int n){
        for(int i=0; i<n; i++){
            nodeToIndex[in[i]] = i;
        }
    }
    
    Node* solve(int in[],int pre[], int &index,int inOrderStart, int inOrderEnd, int n,map<int,int> &nodeToIndex){
        // Base Case
        if(index >= n || inOrderStart > inOrderEnd) {
            return NULL;
        }
        // Create a root node for element
        int element = pre[index++];
        Node* root = new Node(element);
        // Find elements's index inorder
        int position = nodeToIndex[element];
        
        // recursive call
        root->left = solve(in,pre,index,inOrderStart, position-1, n,nodeToIndex);
        root->right = solve(in,pre,index,position+1,inOrderEnd, n,nodeToIndex);
        
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        map<int,int> nodeToIndex;
        // Creates Node to index map
        createMapping(in,nodeToIndex,n);
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n,nodeToIndex);
        return ans;
    }
};