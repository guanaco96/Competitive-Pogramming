/* This algorithm compiles a prefix_sum array and then
* checks whether total sum is divided by 3, if not it prints 0
* otherwise it scans prefix sum form left to right adding combos
* in linear time. Indeed it just has to remeber the number of
* prefix cells containing prefix[n-1]/3 met so far and adding that
* number while meeting a cell containing 2*prefix[n-1]/3.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n;
	cin>>n;
	vector<ll> prefix(n);
	for(ll i=0; i<n; i++){
		cin>>prefix[i];
		prefix[i]+= i>0 ? prefix[i-1] : 0;
	}
	if(prefix[n-1]%3!=0) cout<<0<<endl;
	else{
		ll one=prefix[n-1]/3;
		ll two=2*one;
		ll one_ctr=0;
		ll tot=0;
		for(ll i=0; i<n-1; i++){
			if(prefix[i]==two) tot+=one_ctr;
			if(prefix[i]==one) one_ctr++;
		}
		cout<<tot<<endl;
	}
	return 0;
}
