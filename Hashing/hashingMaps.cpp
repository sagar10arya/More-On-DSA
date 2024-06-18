<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // PreCompute
    map<int, int> mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }

    // Iterate in the map
    // for(auto itr: mpp){
    //     cout<<itr.first<<" -> "<<itr.second<<endl;
    // }

    int q;
    cin>>q;
    
    while(q--){
        int number;
        cin >> number;

        // fetch
        cout<<mpp[number]<<endl;
    }

    return 0;
=======
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // PreCompute
    map<int, int> mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }

    // Iterate in the map
    // for(auto itr: mpp){
    //     cout<<itr.first<<" -> "<<itr.second<<endl;
    // }

    int q;
    cin>>q;
    
    while(q--){
        int number;
        cin >> number;

        // fetch
        cout<<mpp[number]<<endl;
    }

    return 0;
>>>>>>> 6707f6c60ec048ffb97870212162c5add4e17f66
}