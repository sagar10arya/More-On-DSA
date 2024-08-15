#include<bits/stdc++.h>
using namespace std;


int main()
{
    // Max Heap  -> default
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(6);
    pq.push(1);
    pq.push(8);

    cout<<"Top element of Priority queue: "<<pq.top()<<endl;    // max element hoga
    pq.pop();  // top element/max will be popped
    cout<<"Top element of Priority queue after pop: "<<pq.top()<<endl;    // max element hoga

    cout<<"Size: "<<pq.size()<<endl;

    if(pq.empty()){
        cout<<"Priority queue is empty"<<endl;
    }
    else cout<<"Not empty"<<endl;

    // Min Heap
    cout<<"Min Heap STL: "<<endl;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(6);
    minHeap.push(8);

    cout<<"Top element of Priority queue: "<<minHeap.top()<<endl;    // max element hoga
    minHeap.pop();  // top element/min will be popped
    cout<<"Top element of Priority queue after pop: "<<minHeap.top()<<endl;    // max element hoga

    cout<<"Size: "<<minHeap.size()<<endl;

    if(minHeap.empty()){
        cout<<"Priority queue is empty"<<endl;
    }
    else cout<<"Not empty"<<endl;


    return 0;
}
