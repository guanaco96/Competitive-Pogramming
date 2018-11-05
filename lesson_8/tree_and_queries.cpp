/* This algorithm linearizes the input tree
 * using a DFS: in this way subtrees are easily
 * detectable and we take save them in the array
 * vert_to_lin. Thus the problem is reduced to a
 * collection of simple colored array queries that
 * can be solved in O(sqrt(n)*(n+m)) using Moe's algorithm. 
 */
#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
constexpr int N=100001;

int freq[N];
int color[N];
int father[N];
int ks[N];
vector<vector<int>> tree;
vector<int> lin;
vector<pair<int,int>> vert_to_lin;

void trans(int os, int oe, int ns, int ne){
	while(os<ns) ks[freq[lin[os++]]--]--;
	while(os>ns) ks[++freq[lin[--os]]]++;
	while(oe<ne) ks[++freq[lin[oe++]]]++;
}	

void DFS(int index){
	vert_to_lin[index].first=lin.size();
	lin.push_back(color[index]);
	for(vector<int>::iterator it=tree[index].begin(); it!=tree[index].end(); it++){
		if(*it!=father[index]){
			father[*it]=index;
			DFS(*it);
		}
	}
	// left-closed interval [ vert_to_lin[v], vert_to_lin[v] )
	// denotes linearized v-rooted subtree
	vert_to_lin[index].second=lin.size();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin>>n>>m;
	for(int i=1; i<n+1; i++) cin>>color[i];
	tree=vector<vector<int>>(n+1);
	for(int i=0; i<n-1; i++){
		int a, b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	vert_to_lin=vector<pair<int,int>>(n+1);
	DFS(1);
	int sq=sqrt(n);
	int bl=n/sq+1;
	vector<vector<tuple<int,int,int>>> query(bl);
	vector<tuple<int,int,int>> num_to_tuple(m);
	for(int i=0; i<m; i++){
		int v, k;
		cin>>v>>k;
		tuple<int,int,int> tt=make_tuple(vert_to_lin[v].second, vert_to_lin[v].first, k);
		num_to_tuple[i]=tt;
		// ACHTUNG! tuple is (r,l,k) not to redefine comparison 4 sorting
		query[vert_to_lin[v].first/sq].push_back(tt);
	}
	map<tuple<int,int,int>,int> tuple_to_res;
	for(int i=0; i<bl; i++){
		vector<tuple<int,int,int>>::iterator it=query[i].begin();
		if(it==query[i].end()) continue;
		for(int i=0; i<N; i++) freq[i]=ks[i]=0;
		sort(query[i].begin(), query[i].end());
		for(int i=get<1>(*it); i<get<0>(*it); i++) ks[++freq[lin[i]]]++;
		tuple_to_res.insert(make_pair(*it,ks[get<2>(*it)]));
		for(it++; it!=query[i].end(); it++){
			trans(get<1>(*(it-1)), get<0>(*(it-1)), get<1>(*it), get<0>(*it));
			tuple_to_res.insert(make_pair(*it,ks[get<2>(*it)]));
		}
	}
	for(int i=0; i<m; i++) cout<<tuple_to_res[num_to_tuple[i]]<<endl;		
		
	return 0;
}
