/* This algorithm runs in O(n log(n)).
 * It sorts segments, intended as a pair (l,r)
 * denotig its endpoints, by lexicographical 
 * decreasing order. Then treats endpoints r_i
 * as if they were their relative position (because
 * our bound on r_is is not narrow enough) and
 * processes segment as ordered counting how many r_i
 * already processed are less or equal to the current one.
 * This can be done in log(n) using a Fenwick tree.
 */ 

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
constexpr int N=200001;

map<int,int> pos; // r_i --> r_i position in (r_i)_i sorted
map<int,int> cont; // l_i --> number of segment contained in (l_i, r_i) 
int bit[N+1];

void update(int index, int val){
	index++;
	while(index<N){
		bit[index]+=val;
		index+=index & (-index);
	}
}

int get(int index){
	index++;
	int sum=0;
	while(index>0){
		sum+=bit[index];
		index-=index & (-index);
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int	n;
	cin>>n;
	vector<pair<int,int>> v(n);
	vector<int> r(n);
	for(int i=0; i<n; i++){
		cin>>v[i].first>>v[i].second;
		r[i]=v[i].second;
	}
	vector<pair<int,int>> w(v);
	sort(w.begin(), w.end());
	reverse(w.begin(), w.end());
	sort(r.begin(), r.end());
	for(int i=0; i<n; i++) pos.insert(make_pair(r[i],i));
	for(int i=0; i<n; i++) w[i].second=pos[w[i].second];
	for(int i=0; i<n; i++){
		cont.insert(make_pair(w[i].first, get(w[i].second)));
		update(w[i].second, 1);
	}
	for(int i=0; i<n; i++) cout<<cont[v[i].first]<<endl;	
	
	return 0;
}
