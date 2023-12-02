#include<bits/stdc++.h>
using namespace std;

class CircularQueue{
    public:
    int *arr;
    int rear;
    int front;
    int size;

    CircularQueue(int n){
        size = n;
        front = rear = -1;
    }

    bool enqueue(int value){
        // to check whether queue is full
        if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            cout<<"Queue is Full."<<endl;
            return false;
        }
        else if(front == -1) // first element to push
        {
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;   // to maintain cyclic nature
        }
        else{
            // Normal flow
            rear++;
        }
        // Push inside the code
        arr[rear] = value;
        return true;
    }

    int dequeue(){
        // To check whether queue is empty
        if(front == -1){
            cout<<"Queue is empty."<<endl;
            return false;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear) { // single element is present
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;  // to maintain cyclic nature
        }
        else{
            // Normal flow
            front++;
        }
        return ans;
    }
};