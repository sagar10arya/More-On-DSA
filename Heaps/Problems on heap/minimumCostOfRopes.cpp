#include <bits/stdc++.h>
using namespace std;
/*
There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths.
The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes. 
*/

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // create a min heap
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
        }
        
        long long cost = 0;
        
        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();
            
            long long b = pq.top();
            pq.pop();
            
            long long sum = a + b;
            
            cost += sum;
            
            pq.push(sum);
        }
        return cost;
    }
};