#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the data:"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1) return NULL;

    cout<<"Enter data for inserting in left of "<< data << endl;
    root->left = buildTree(root->left);

    cout<<"Enter data for inserting in right of "<< data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            // purana level is traversed completely
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data <<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void reverseOrderTraversal(node* root){
    queue<node*> q;
    stack<node*> s;
    
    // Enqueue the root node in the queue
    q.push(root);

    while(!q.empty()){
        /* Dequeue Node and make it root */
        root = q.front();
        q.pop();
        s.push(root);
        
        /* Enqueue right child*/
        if(root->right){
            q.push(root->right); // Right child is enqueued before left
        }

        /* Enqueue left child*/
        if(root->left){
            q.push(root->left); 
        }
    }
    /* Pop all the items from stack and print*/
    while(!s.empty()){
        root = s.top();
        s.pop();
        cout<<root->data<<" ";
    }
}


void inOrder(node* root){
    // Base Case
    if(root == NULL){
        return;
    }
    // LNR
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(node* root){
    // Base Case
    if(root == NULL) return;
    
    //NLR
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}


void postOrder(node* root){
    // Base Case
    if(root == NULL) return;
    
    //LRN
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter data from root "<<endl;
    int data;
    cin>>data;
    root  = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main(){

    node* root = NULL;

    buildFromLevelOrder(root);
    // 5 3 2 7 9 8 -1 -1 -1 -1 -1 -1 -1 -1
    levelOrderTraversal(root);

    /*
    // Creating a Tree
    root = buildTree(root);

    // 5 3 7 -1 -1 9 -1 -1 2 8 -1 -1 11 -1 -1
    
    cout << "Printing Level Order Traversal" <<endl;
    levelOrderTraversal(root);
    
    cout << "Printing Reverse Level Order Traversal" <<endl;
    reverseOrderTraversal(root);

    cout<<endl;

    cout<<"Printing InOrder : "<<endl;
    inOrder(root);

    cout<<endl;
    
    cout<<"Printing PreOrder : "<<endl;
    preOrder(root);

    cout<<endl;
    
    cout<<"Printing PostOrder : "<<endl;
    postOrder(root);

    */

    return 0;
}