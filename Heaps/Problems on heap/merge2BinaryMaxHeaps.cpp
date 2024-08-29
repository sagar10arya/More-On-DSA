#include <bits/stdc++.h>
using namespace std;
/*
Given two binary max heaps as arrays, merge the given heaps to form a new max heap.
*/

class Solution{
    public:
    void heapify(vector<int> &ans, int n, int i){
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        
            if(left < n && ans[largest] < ans[left])
                largest = left;
            if(right < n && ans[largest] < ans[right])
                largest = right;
            
            if(largest != i){
                swap(ans[largest], ans[i]);
                heapify(ans, n, largest);
            }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // Step1.  merge both arrays
        vector<int> ans;
        
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        
        // Step 2> heapify -> build heap using merged array
        int size = ans.size();
        for(int i = size/2-1; i>=0; i--){
            heapify(ans, size, i);
        }
        
        return ans;
    }
};