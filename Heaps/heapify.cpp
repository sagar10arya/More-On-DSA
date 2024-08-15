#include<bits/stdc++.h>
using namespace std;

/*
1. heapify max
2. heapify min
*/
// 0 - Based indexing
void buildMaxHeap(int arr[], int n, int i){
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
        buildMaxHeap(arr, n, largest);  // Recursively heapify the affected sub-tree
    }
}

void heapifyMin(int arr[], int n, int i){
    int smallest = i; // Initialize smallest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);

        // Recursively heapify the affected sub-tree
        heapifyMin(arr, n, smallest);
    }
}

int main()
{
    int arr[6] = {54,53,55,52,50};
    int n = 5;

    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for(int i=n/2-1; i>=0; i--){
        buildMaxHeap(arr, n, i);
    }

    cout<<"Printing Max Heap:"<<endl;

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Printing Min Heap:"<<endl;


    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = n/2 - 1; i >= 0; i--) {
        heapifyMin(arr, n, i);
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}