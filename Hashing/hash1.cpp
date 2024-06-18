<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }


    // Precompute
    int hash[13] = {0};
    for(int i=0; i<n; i++){
        hash[arr[i]] += 1;
    }

    int q;
    cin>>q;

    while(q--){
        int number;
        cin>>number;
        // fetch
        cout << hash[number] <<endl;
    }


















    return 0;
=======
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }


    // Precompute
    int hash[13] = {0};
    for(int i=0; i<n; i++){
        hash[arr[i]] += 1;
    }

    int q;
    cin>>q;

    while(q--){
        int number;
        cin>>number;
        // fetch
        cout << hash[number] <<endl;
    }


















    return 0;
>>>>>>> 6707f6c60ec048ffb97870212162c5add4e17f66
}