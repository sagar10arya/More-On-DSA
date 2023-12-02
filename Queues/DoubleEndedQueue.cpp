#include<bits/stdc++.h>
using namespace std;

class Deque{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    Deque(int n){
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    // Pushes 'X' into the front of dequeue,return true if it gets pushed
    bool pushFront(int x) {
        // to check whether queue is full
        if(isFull()){
            cout<<"Queue is Full."<<endl;
            return false;   
        }
        else if(isEmpty()) // first element to push
        {
            front = rear = 0;
        }
        else if(front == 0 && rear != size-1){
            front = -1;
        }
        else{
            // Normal flow
            front--;
        }
        // Push inside the code
        arr[rear] = x;
        return true;
    }

    // Pushes 'X' into the back of dequeue,return true if it gets pushed
    bool pushRear(int x) {
         // to check whether queue is full
        if( isFull()){
            cout<<"Queue is Full."<<endl;
            return false;   
        }
        else if(isEmpty()) // first element to push
        {
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
        }
        else{
            // Normal flow
            rear++;
        }
        // Push inside the code
        arr[rear] = x;
        return true;
    }


    // Pops an element from the front of dequeue, return -1 if dequeue is empty,otherwise return popped element
    int popFront(){
        // To check whether queue is empty
        if(isEmpty()){
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

    // Pops an element from the back of dequeue, return -1 if dequeue is empty,otherwise return popped element
    int popRear(){
        // To check whether queue is empty
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
            return false;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if(front == rear) { // single element is present
            front = rear = -1;
        }
        else if(rear == 0){
            rear = size-1;  // to maintain cyclic nature
        }
        else{
            // Normal flow
            rear--;
        }
        return ans;
    }

    // Return the first element of the dequeue. If dequeue is empty return -1
    int getFront(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Return the last element of the dequeue. If dequeue is empty return -1
    int getRear(){
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // return true if the dequeue if empty, otherwise return false
    bool isEmpty(){
        if(front == -1) return true;
        else return false;
    }

    // return true if the dequeue if full, otherwise return false
    bool isFull(){
        if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1)))
        return true;
        else return false;
    }
};