#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:

    int *arr;
    int front;
    int rear;
    int size;

    Queue(){
        // Implement the Constructor
        size = 10001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    /* Public functions of Queue*/

    bool isEmpty(){
        if(front == rear){
           return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data){
        // Implement the enqueue function
        if(rear == size){
            cout<<"Queue is Full"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue(){
        // Implement the dequeue function
        if(front == rear){
            cout<<"Queue is empty"<<endl;
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
        return ans;
        }
    }

    int front(){
        // Implement the front function
        if(front == rear){
            cout<<"Queue is empty"<<endl;
        }
        else{
            return arr[front];
        }
    }
};