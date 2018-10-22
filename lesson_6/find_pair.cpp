/* This algorithm stores a vector w containing
 * pairs of integers consisting of an element and its
 * frquency in input array. Please note that w is 
 * constructed so that it's naturally order by ascending 
 * first component. Then our problem is equivalent to the
 * following: given a square tab filled with integers
 * such that any row sums n, find the cell such that 
 * summing the content of all its predecessors we obtain k.
 * This can easily be done in linear time chaining two loops
 * so that the first one scans rows and the second one scans
 * columns.
 */ 

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,k;
	cin>>n>>k;
	vector<ll> v(n);
	for(ll i=0; i<n; i++) cin>>v[i];
	sort(v.begin(),v.end());
	vector<pair<ll,ll>> w;
	ll i=0;
	while(i<n){
		ll fr=0;
		ll val=v[i];
		while(i<n && val==v[i]){
			fr++;
			i++;
		}
		w.push_back(make_pair(val,fr));
	}
	ll ctr=0;
	vector<pair<ll,ll>>::iterator it=w.begin();
	while(ctr+it->second*n<k) ctr+=it++->second*n;
	cout<<it->first<<" ";
	vector<pair<ll,ll>>::iterator is=w.begin();
	while(ctr+is->second*it->second<k) ctr+=is++->second*it->second;
	cout<<is->first<<endl;
	
	return 0;
}
