#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        
        // Step1: first k elements ka max heap
        for(int i=0; i<k; i++){
            pq.push(arr[i]);
        }
        
        // Step2.   for rest elements
        for(int i=k; i<arr.size(); i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};