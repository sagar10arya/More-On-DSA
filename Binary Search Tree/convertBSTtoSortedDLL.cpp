#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};


// Convert BST to sorted doubly linked list 

void convertBSTtoSortedDLL(Node *root, Node *head){
    // Base Case
    if(root == NULL) return NULL;

    convertBSTtoSortedDLL(root->right, head);

    root->right = head;
    if(head != NULL)
        head->left = root;
    
    head = root;

    convertBSTtoSortedDLL(root->left, head);
}