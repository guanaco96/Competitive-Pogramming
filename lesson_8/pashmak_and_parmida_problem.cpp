/* This algorithm precompute the values of f(1,i,a_i)
 * and f(i,n,a_i) in O(n log(n)) using C++ associative 
 * arrays. Then makes use of a fenwick tree to remeber
 * the number #{j | f(j, n, a_j)=k} for k=0,..,n updating
 * dynamically the data structure while scanning the array.
 * This works in O(n log(n)).
 */
#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
constexpr int N=1000001;

int bit[N];

void update (int index, int val){
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
		index-= index & (-index);
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	map<int,int> tab;
	vector<int> f(n);
	for(int i=0; i<n; i++){
		map<int,int>::iterator it=tab.find(v[i]);
		if(it==tab.end()){
			tab.insert(make_pair(v[i],1));
			f[i]=1;
		}
		else f[i]=++it->second;
	}
	vector<int> g(n);
	for(int i=0; i<n; i++) update(g[i]=tab[v[i]]-f[i]+1, 1);
	ll tot=0;
	for(int i=0; i<n; i++){
		update(g[i], -1);
		tot+=get(f[i]-1);
	}
	cout<<tot<<endl;
	
	return 0;
}
