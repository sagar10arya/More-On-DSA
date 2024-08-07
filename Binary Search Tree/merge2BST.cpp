#include <bits/stdc++.h>
using namespace std;

class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };


void inorder(TreeNode<int>* root, vector<int> &in){
    if(root == NULL) return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b){
    vector<int> ans(a.size() + b.size());

    int i=0, j=0;
    int k = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            // ans.push_back(a[i]);
            ans[k++] = a[i];
            i++;
        }
        else{
            ans[k++] = a[j];
            j++;
        }
    }

    while( i < a.size()){
        ans[k++] = a[i];
        i++;
    }

    while( j < b.size()){
        ans[k++] = a[j];
        j++;
    }
    return ans;
}

TreeNode<int>* inorderToBST(int s, int e, vector<int>& in)   
 {
    if (s > e) return NULL; // Base case
    int mid = (s + e) / 2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root->left = inorderToBST(s, mid - 1, in);
    root->right = inorderToBST(mid + 1, e, in);
    return root;   

}

vector<int>* mergeBST(TreeNode* root1, TreeNode* root2) {
    // Step 1. Store inorder
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    // Step 2. Merge 2 sorted arrays
    vector<int> mergedArray = mergeArrays(bst1, bst2);
    
    // // Step 3. inorder to BST
    int s = 0, e = mergedArray.size() - 1;
    return inorderToBST(s, e, mergedArray);
}