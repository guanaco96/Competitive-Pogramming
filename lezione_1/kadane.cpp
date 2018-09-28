/* This algorithm is greedy. It scans the input once
 * memorizing both the sum of the last k elements such that 
 * any starting sub array of those k elements has positive sum 
 * and the maximum of those sums met so far.
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	for(int j=0; j<T; j++){
		int n;
		cin>>n;
		int curr=0;
		int max=-1000;
		for(int i=0; i<n; i++){
			int tmp;
			cin>>tmp;
			if(curr<0) curr=0;
			curr+=tmp;
			if(max<curr) max=curr;
		}
		cout<<max<<endl;
	}
	
	return 0;
}

