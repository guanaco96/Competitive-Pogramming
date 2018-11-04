/* This is just Moe's Algorithm.
 * I've divided interval [1,n] into
 * sqrt(n) blocks of length sqrt(n)
 * and then divided queries depending on
 * which block their starting points belong.
 * Processing queries in this order gives us
 * the satisfying O(sqrt(n)*(n+t)) complexity.
 */
 #include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
constexpr ll N=200001;
constexpr ll M=1000001;

ll a[N];
ll val[M];
map<pair<ll,ll>,ll> q_to_res;

ll trans(ll os, ll oe, ll ns, ll ne){
	ll tot=0;
	if(os>ns){
		for(ll i=ns; i<os; i++){
			tot+=a[i]*(2*val[a[i]]+1);
			val[a[i]]++;
		}
	}
	else{
		for(ll i=os; i<ns; i++){
			val[a[i]]--;
			tot-=a[i]*(2*val[a[i]]+1);			
		}
	}
	for(ll i=oe+1; i<=ne; i++){
		tot+=a[i]*(2*val[a[i]]+1);
		val[a[i]]++;
	}
	return tot;
}		

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, t;
	cin>>n>>t;
	for(ll i=1; i<n+1; i++) cin>>a[i];
	ll sq=sqrt(n);
	ll bl=n/sq+1;
	vector<vector<pair<ll,ll>>> query(bl);
	// to remember queries numbers
	vector<pair<ll,ll>> num_to_q(t); 
	for(ll i=0; i<t; i++){
		pair<ll,ll> p;
		//ACHTUNG: in order to use default lexicographical order on
		// pairs we'r saving pairs like (r,l).
		cin>>p.second>>p.first;
		query[p.second/sq].push_back(p);
		num_to_q[i]=p;
	}
	for(ll i=0; i<bl; i++){
		vector<pair<ll,ll>>::iterator it=query[i].begin();
		if(it==query[i].end()) continue;
		sort(query[i].begin(), query[i].end());
		for(ll i=0; i<M; i++) val[i]=0;
		ll tot=0;
		for(ll i=it->second; i<=it->first; i++){
			tot+=a[i]*(2*val[a[i]]+1);
			val[a[i]]++;
		}
		q_to_res.insert(make_pair(*it,tot));
		for(it++; it!=query[i].end(); it++){
			tot+=trans((it-1)->second, (it-1)->first, it->second, it->first);
			q_to_res.insert(make_pair(*it,tot));
		}
	}
	for(ll i=0; i<t; i++) cout<<q_to_res[num_to_q[i]]<<endl;	
	
	return 0;
}
