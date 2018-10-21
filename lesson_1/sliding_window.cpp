/* This algorithm stores a decreasing sequence of values
* that is sufficient to determine the max k-width windows 
* array since we can ignore elements having value & index
* smaller than the current added value.
* This code runs in linear time.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T-->0){
		int n,k;
		cin>>n>>k; 
		deque<pair<int,int>> deq;
		for(int i=0; i<n; i++){
			if(!deq.empty() && i-deq.front().second>=k) deq.pop_front();
			int x;
			cin>>x;
			while(!deq.empty() && deq.back().first<x) deq.pop_back();
			deq.push_back(make_pair(x,i));
			if(i>=k-1) cout<<deq.front().first<<" ";
		}
		cout<<endl;
	}			
	
	return 0;
}
