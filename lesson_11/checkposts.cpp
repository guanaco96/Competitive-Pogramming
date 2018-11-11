/* This algorithm finds biconnected components
 * in routes graph in O(m).
 * It uses both a DFS and an union find data 
 * structure as follows: any node's ancestor in
 * union find tree is the most shallow node of its
 * biconnected component discovered so far.
 * Then DFS recursively finds biconnected component
 * while current node has a son which belongs to
 * a bidirected component represented in union-find
 * by a node still in the DFS node stack.
 */

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
constexpr int N=100001;
constexpr ll MOD=1000000007;

int seen[N];
int ft[N];
int deep[N];

int find(int node){
	while(ft[node]!=node){
		int tmp=node;
		node=ft[node];
		ft[tmp]=ft[node];
	}
	return node;
}
// ACHTUNG: in this version of union-find order of union arguments
// matters!
void uni(int n1, int n2){
	n1=find(n1);
	n2=find(n2);
	ft[n1]=n2;
}

void DFS(int node, vector<vector<int>> &graph, int dp){
	seen[node]=-1;
	deep[node]=dp;
	for(vector<int>::iterator it=graph[node].begin(); it!=graph[node].end(); it++){
		int cc=find(*it);
		if(seen[cc]==0)	DFS(*it, graph, dp+1);
		cc=find(*it);
		if(seen[cc]==-1){
			if(deep[find(node)]>deep[cc]) uni(node, cc);
			else uni(cc, node);
		}
	}
	seen[node]=1;
}	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<int> cost(n);
	for(int i=0; i<n; i++) cin>>cost[i];
	vector<vector<int>> graph(n);
	for(int i=0; i<n; i++) ft[i]=i;
	int m;
	cin>>m;
	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		graph[--a].push_back(--b);
	}
	for(int i=0; i<n; i++) if(seen[i]==0) DFS(i, graph, 0);
	vector<pair<ll,ll>> min_freq(n, make_pair(MOD,0));
	for(int i=0; i<n; i++){
		int cc=find(i);
		if(cost[i]<min_freq[cc].first) min_freq[cc]=make_pair(cost[i],0);
		if(cost[i]==min_freq[cc].first) min_freq[cc].second++;
	}
	ll combo=1;
	ll money=0;
	for(int i=0; i<n; i++){
		if(min_freq[i].second>0){
			money+=min_freq[i].first;
			combo=(combo*min_freq[i].second)%MOD;
		}
	}
	cout<<money<<" "<<combo<<endl;
	
	return 0;
}
