// Function to reverse first k elements of a queue.
#include<bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    
    // Step1. Pop first k from Q and put into stack
    stack<int> s;
    for(int i=0; i<k; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }
    
    //Step2. Fetch from stack and push into q
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }
    
    // Step3. Fetch first n-k elements from Q and push back
    int t = q.size()-k;
    
    while(t--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}