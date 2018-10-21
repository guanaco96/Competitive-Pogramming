/* This algorithm runs in O(n log(n)). It compiles
 * time vector adding 1 at address l and -1 at r+1
 * if r+1 belongs to [1..n]. Then it computes the 
 * prefix sum array counting how many times a term
 * appears in the final sum. Then we just need to
 * sort our vectors and pick 'em up in the right 
 * order to maximize sum.
 */

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,q;
	cin>>n>>q;
	vector<ll> v(n);
	for(ll i=0; i<n; i++) cin>>v[i];
	vector<ll> time(n);
	for(ll i=0; i<q; i++){
		ll l,r;
		cin>>l>>r;
		time[--l]++;
		if(--r+1<n) time[r+1]--;
	}
	for(ll i=1; i<n; i++) time[i]+=time[i-1];
	sort(time.begin(),time.end());
	reverse(time.begin(),time.end());
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	ll sum=0;
	for(ll i=0; i<n; i++) sum+=time[i]*v[i];
	cout<<sum<<endl;
	
	return 0;
}
