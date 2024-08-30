#include<bits/stdc++.h>
using namespace std;

/* You are given two integers L and R, your task is to find the XOR of elements of the range [L, R]. 
Your task is to complete the function findXOR() which takes two integers l and r and returns the XOR of numbers from l to r.

Time Complexity: O(1).
Space: O(1).
*/

class Solution {
  public:
    // You can find of n numbers xor from this function
    int XOR(int n){
        if(n%4 == 1) return 1;
        else if(n%4 == 2) return n+1;
        else if(n%4 == 3) return 0;
        else return n;
    }
    
    int findXOR(int l, int r) {
        return XOR(l-1) ^ XOR(r);
    }
};