#include<bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin>>s;

    // Precompute

    // just for smaller case
    // int hash[26] = {0};
    // for(int i=0; i<s.size(); i++){
    //     hash[s[i]-'a']++;
    // }

    // if you dont have such condition like above then we know 256 ASCII
    int hash[256] = {0};
    for(int i=0; i<s.size(); i++){
        hash[s[i]]++;
    }

    int q;
    cin>>q;
    while(q--){
        char ch;
        cin>>ch;
        // fetch
        // cout << hash[ch- 'a'] << endl; ## output for lines 13-16
        cout << hash[ch] << endl;
    }

    return 0;
}