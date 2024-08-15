#include<bits/stdc++.h>
using namespace std;


void heapify(int arr[], int n, int i){
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if(left < n && arr[largest] < arr[left]) largest = left;
    // If right child is larger than largest so far
    if(right < n && arr[largest] < arr[right]) largest = right;

    // If largest is not root
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);  // Recursively heapify the affected sub-tree
    }
}


// 0 - based indexing
void heapSort(int arr[], int n){    
    int size = n-1;

    while(size > 1){
        // Step 1: Swap the current root to the end    
        swap(arr[size], arr[0]);
        size--;

        // step2: take root to its correct position
        heapify(arr, size, 0);  // Always start with index 0
    }
}


int main(){

    int arr[6] = {54,53,55,52,50};
    int n = 5;

    // Heap Creation
    for(int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }

    cout<<"Printing Max Heap:"<<endl;

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Heap Sort:"<<endl;
    heapSort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}