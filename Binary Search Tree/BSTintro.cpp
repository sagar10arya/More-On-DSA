#include <bits/stdc++.h>
using namespace std;

/* What is in this Code:
1. Insertion 2. Deletion 3. Level Order Traversal 4. Min and Max Value
*/

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

// Minimum Value
Node* minVal(Node* root){
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

// Maximun Value
Node* maxVal(Node* root){
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

// Breadth First Search
void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return;
    }

    // Start with an empty queue and add the root node to it.
    queue<Node*> q;
    q.push(root);
    q.push(NULL);    // Marker for end of level

    // Processing Nodes Level by Level:
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {           
            cout << endl; // End of current level
            if (!q.empty()) {
                // Queue still has some child nodes
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) {
        return new Node(d);
    }

    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(Node*& root) {
    int data;
    cout << "Enter node value (end with -1): ";
    cin >> data;

    while (data != -1) {
        cout << "Inserting " << data << endl;
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

Node* deleteFromBST(Node* root, int val){
    if(root == NULL) return root; // Base Case

    if(root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child

        // left Child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // right Child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }


    }
    else if(root->data > val){
        // left part
        root->left = deleteFromBST(root->left, val);
    }
    else{
        // right part
        root->right = deleteFromBST(root->right, val);
    }
}

int main() {
    Node* root = NULL;
    cout << "Take data to create BST: " << endl;
    takeInput(root);

    cout << "Printing the BST: " << endl;
    levelOrderTraversal(root);

    cout<<"Minimum value in BST: "<< minVal(root)->data << endl;
    cout<<"Maximum value in BST: "<< maxVal(root)->data << endl;

    // Deletion
    root = deleteFromBST(root, 30);

    cout << "Printing the BST After deletion: " << endl;
    levelOrderTraversal(root);

    return 0;
}

// 50 20 70 10 30 90 110 -1