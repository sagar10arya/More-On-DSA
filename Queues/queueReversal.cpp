#include<bits/stdc++.h>
using namespace std;

class QueueReverse
{
    public:
    queue<int> rev(queue<int> q)
    {
        stack<int> s;
        
        while(!q.empty()){
            int element = q.front();
            q.pop();
            s.push(element);
        }
        
        while(!s.empty()){
            int element = s.top();
            s.pop();
            q.push(element);
        }
        return q;
    }
};
