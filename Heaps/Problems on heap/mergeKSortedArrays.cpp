#include <bits/stdc++.h>
using namespace std;

/*
You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.
*/


class node{
    public:
    int data;
    int  i;
    int j;

    node(int data, int row, int col){
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
    public:
    bool operator()(node*a, node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare> minHeap;

    // Step1. insert first  element of all k arrays
    for(int i=0; i<k; i++){
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    // Step2. 
    while(minHeap.size() > 0){
        node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->i;
        int j = temp->j;

        if(j+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1], i, j+1);
            minHeap.push(next);
        }

    }
    return ans;
}
