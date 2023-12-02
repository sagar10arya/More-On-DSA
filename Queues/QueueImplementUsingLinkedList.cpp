#include<bits/stdc++.h>
using namespace std;

class QNode{
    public:
    int data;
    QNode* next;

    QNode(int x){
        // Implement the Constructor
        data = x;
        *next = NULL;   
    }
};

class Queue{
    QNode *rear, *front;
    Queue(){
        front = NULL;
        rear = NULL;
    }

    void enqueue(int x){
    //  Create a new LL
    QNode* temp = new QNode(x);

    // If queue is empty, then
    // new node is front and rear both
    if(front == rear){
        front = rear = temp;
        return;
    }
    else{
        // Add the new node at
        // the end of queue and change rear
        rear->next = temp;
        rear = temp;
    }
    }
    
    void dequeue(){
        // if queue is empty return NULL
        if(front == NULL) return;

        // Store previous front and
        // move front one node ahead
        QNode* temp = front;
        front = front->next; 

        // If front becomes NULL, then
        // change rear also as NULL
        if(front == NULL){
            rear = NULL;
        }
        delete temp;
    }
};
