#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        
     int n = q.size();
    queue<int> second;
    for(int i=0; i<n/2; ++i){
        int t=q.front();
        q.pop();

        second.push(t);
    }

    for(int i=0; i<n/2; ++i){
        int t=second.front();
        second.pop();

        q.push(t);

        t = q.front();
        q.pop();

        q.push(t);
     }
     
      vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }

};