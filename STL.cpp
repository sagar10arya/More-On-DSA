#include<bits/stdc++.h>
using namespace std;

void explainPair(){
    pair<int,int> p = {1,3};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int,int>> q = {1,{2,3}};
    cout << q.first << " " << q.second.first << " " << q.second.second << endl;

    pair<int,int> arr[] = { {1,2}, {3,4}, {4,5}, {6,7}};
    cout<<arr[1].first;
}

void explainVector(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
    v.emplace_back(3);
    v.emplace_back(4);
    v.emplace_back(5);

    vector<pair<int,int>> vec;

    vec.push_back({1,2});
    vec.emplace_back(1,2);

    vector<int> v1(5,100); // 5 values with 100  each

    vector<int> v2(5); // Can be increased with push_back

    vector<int> vA(5,20);
    vector<int> vB(vA); // Copy of v1

    /*      How to access elements in a vector      */
    vector<int> :: iterator it = v.begin();
    // v.begin() directly points to the memory not the element
    cout << *(it) << " ";
    it = it + 2; // shifts by two addresses
    cout << *(it) << " ";
    cout<<endl;

    // vector<int> :: iterator it = v.end(); // Points right after the last element

    for(vector<int> :: iterator it = v.begin(); it != v.end(); it++){
        cout<<*(it) << " ";
    }
    cout<<endl;
    // vector<int> :: iterator <--> auto
    for(auto it = v.begin(); it != v.end(); it++){
        cout<<*(it) << " ";
    }
    cout<<endl;
    for(auto it : v){
        cout<<it<<" ";  
    }

    /* Erase Function */
    // 10 20 30 40
    v.erase(v.begin()+1); // 10 30 40
    
    // 10 20 30 35 40
    v.erase(v.begin() + 2, v.begin() + 4); // 10 20 40

    /* Insert Function */
    vector<int> v(2,100); // 100 100
    v.insert(v.begin(),300); // 300 100 100
    v.insert(v.begin()+1,2,10); // 300 10 10 100 100

    vector<int> copy(2,50); // 50 50
    v.insert(v.begin(), copy.begin(), copy.end()); // 50 50 300 10 10 100 100

    // {10,20}
    cout << v.size(); //2

    // {10.20}
    v.pop_back(); // 
    
    // v1->{10,20}
    // v2->{30,40}
    v1.swap(v2); // v1->{30,40} , // v2->{10,20}

    v.clear(); //Erase the entire vector
    cout << v.empty(); // True or fasle

}

void explainList(){
    list<int> ls;
    
    ls.push_back(1); //1
    ls.emplace_back(2); //1 2

    ls.push_front(4); // 4 1 2
    ls.emplace_front(3); // 3 4 1 2

   /* Rest Functions are same as vector
    begin, end, rbegin, rend, clear, insert, size, swap */
}

void explainDeque(){
    deque<int> dq;
    dq.push_back(10); // 10
    dq.emplace_back(20); // 10 20
    dq.push_front(4); // 4 10 20
    dq.emplace_front(3); // 3 4 10 20

    dq.pop_back(); // 3 4 10
    dq.pop_front(); // 4 10

    /* Rest Functions are same as vector
    begin, end, rbegin, rend, clear, insert, size, swap */
    // O(1)
}

void explainqueue(){
    queue<int> q;
    q.push(1); //   {1}
    q.push(2); // {1 2}
    q.push(3); // {1 2 3}

    q.back()+=5;
    cout<<q.back(); //prints 8

    // Queue is {1,2,9}
    q.front(); // {1}
    q.pop(); // {2, 9}

    cout<< q.front(); // prints 2

    // size swap empty same as stack
    // O(1)
}

void explainPQ(){
    // Priority Queue --> who has largest value stays at the top

    /* Maximum Heap */
    priority_queue<int> pq;
    pq.push(5); //   {5}
    pq.push(2); // {5 2}
    pq.emplace(7); // {7 5 2}

    cout<<pq.top(); // prints 7

    pq.pop(); // { 5,2 }

    // size swap empty same as others

    /* Minimum Heap  */
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5); //   {5}
    pq.push(2); // {2 5}
    pq.emplace(7); // {2 5 7}

    // push and pop -> O(log n)
    /// top --> O(1)
}

void explainSet(){
    // Sets stores everything in sorted order and Unique
    set<int> st;
    st.insert(1); // {1}
    st.emplace(2); // {1 2}
    st.insert(2); // {1 2}
    st.insert(5); // {1 2 5}
    st.insert(3); // {1 2 3 5}

    /* Rest Functions are same as others
    begin, end, rbegin, rend, clear, insert, size, swap */

    // {1,2,3,4,5}
    auto it = st.find(3);

    // {1,2,3,4,5}
    auto it = st.find(6); // gives iterator after the end of element    

    st.erase(5); // erases 5
    // {1,2,3,4,5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1,it2); // After erase {1,4,5}

    // Lower bound andd upper bounnd works in same way as in vector it does
    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);

    // Everything in sets happens in O(logn) time   
}

void multiSet(){
    // Everything is same as set but stores duplicate elements
    multiset<int> mt;
    mt.insert(1); // {1 1}
    mt.insert(1); // {1 1}
    mt.insert(1); // {1 1 1}

    mt.erase(1); // Erases all 1's

    int cnt = mt.count(1);

    // only a single 1 erases
    mt.erase(mt.find(1));

    // Rest all of the functions are the same
}

void explainUSet(){
    unordered_set<int> st;
    // Unique but not sorted
    // All the functions are same but
    // Lower bound and upper bound does not work
    // They are O(1) but very very rare it goes for O(n)
}

void explainMap(){
    // Stores in sorted keys and no duplicates
    map<int,int> mpp;
    map<int, pair<int,int>> mpp;
    map<pair<int,int>, int> mpp;

    mpp[1] = 2;
    mpp.insert({3,1});
}

void explainMultiMap(){
    // Same as maps, only it can store multiple keys
    // duplicate keys
}

void explainUnorderedMap(){
    // Unique keys but not sorted
}
