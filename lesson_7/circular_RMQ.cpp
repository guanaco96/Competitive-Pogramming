/* This algorthm just uses the well known
 * range tree lazy update data structure.
 * It doesn't differ too much from the ordinary
 * version, it just queries (or upates) twice the tree
 * while handling an interval having lf>rf.
 */
#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;
constexpr ll MAX=200001;
constexpr ll A_MAX=1000000000000000;

ll tree[MAX<<2];
ll lazy[MAX<<2];
char c[100];

void update(ll val, ll nd, ll us, ll ue, ll is, ll ie){
	if(lazy[nd]!=0){
		tree[nd]+=lazy[nd];
		if(is!=ie){
			lazy[2*nd+1]+=lazy[nd];
			lazy[2*nd+2]+=lazy[nd];
		}
		lazy[nd]=0;
	}
	if(is>ue || ie<us) return;
	if(is>=us && ie<=ue){
		tree[nd]+=val;
		if(is!=ie){
			lazy[2*nd+1]+=val;
			lazy[2*nd+2]+=val;		
		}
		return;

	}
	ll mid=(is+ie)/2;
	update(val, 2*nd+1, us, ue, is, mid);
	update(val, 2*nd+2, us, ue, mid+1, ie);
	tree[nd]=min(tree[2*nd+1], tree[2*nd+2]);
}

ll query(ll nd, ll qs, ll qe, ll is, ll ie){
	if(lazy[nd]!=0){
		tree[nd]+=lazy[nd];
	if(is!=ie){
			lazy[2*nd+1]+=lazy[nd];
			lazy[2*nd+2]+=lazy[nd];
		}
		lazy[nd]=0;
	}
	if(is>qe || ie<qs) return A_MAX;
	if(is>=qs && ie<=qe) return tree[nd];
	ll mid=(is+ie)/2;
	return min(query(2*nd+1, qs, qe, is, mid), query(2*nd+2, qs, qe, mid+1, ie));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	for(ll i=0; i<n; i++){
		ll v;
		cin>>v;
		update(v, 0, i, i, 0, MAX-1);
	}
	ll m;
	cin>>m;
	cin.ignore();
	while(m--){
		cin.getline(c, 100);
		ll l, r, v;
		if(istringstream(c)>>l>>r>>v){
			if(l<=r) update(v, 0, l, r, 0, MAX-1);
			else{
				update(v, 0, 0, r, 0, MAX-1);
				update(v, 0, l, n-1, 0, MAX-1);
			}
		}else{
			if(l<=r) cout<<query(0, l, r, 0, MAX-1)<<endl;
			else cout<<min(query(0, l, n-1, 0, MAX-1), query(0, 0, r, 0, MAX-1))<<endl;
		}
	}		
	
	return 0;
}
