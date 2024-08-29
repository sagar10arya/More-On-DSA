#include <bits/stdc++.h>
using namespace std;

// T.C --> O(n2 log k)   S.C --> O(k)
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int, vector<int>, greater<int>> mini;

	for(int i=0; i<arr.size(); i++){
		int sum = 0;
		for(int j=i; j<arr.size(); j++){
			sum += arr[j];
			if(mini.size() < k){
				mini.push(sum);
			}
			else{
				if(sum > mini.top()){
					mini.pop();
					mini.push(sum);
				}
			}
		}	
	}

	return mini.top();
}



/*
// T.C --> O(n2 log n)   S.C --> O(N2)
int getKthLargest(vector<int> &arr, int k)
{
	vector<int> sumStore;

	for(int i=0; i<arr.size(); i++){
		int sum = 0;
		for(int j=i; j<arr.size(); j++){
			sum += arr[j];
			sumStore.push_back(sum);
		}	
	}

	sort(sumStore.begin(), sumStore.end());

	return sumStore[sumStore.size() - k];
}
*/