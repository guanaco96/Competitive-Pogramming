/* This algorithm performs a static update 
 * of the array A calculating the array diff
 * such that diff[i]==A[i]-A[i-1], defining 
 * A[-1]=0. Hence it's easy to take note
 * of update queries and to answer look_up ones
 * it's sufficient to telescope diff into it's
 * prefix sum array.
 */

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t-->0){
		int n,u;
		cin>>n>>u;
		vector<int> diff(n);
		for(int i=0; i<u; i++){
			int l, r, val;
			cin>>l>>r>>val;
			diff[l]+=val;
			if(r+1<n) diff[r+1]-=val;
		}
		for(int i=1; i<n; i++) diff[i]+=diff[i-1]; 
		int q;
		cin>>q;
		for(int i=0; i<q; i++){
			int ind;
			cin>>ind;
			cout<<diff[ind]<<endl;
		}
	}		
	
	return 0;
}
