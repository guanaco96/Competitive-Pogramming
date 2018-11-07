/* This solution is based upon the idea
 * that being bipartite is equivalent
 * to allow a node 2-coloring such that
 * two adjacent nodes does not share the same color.
 * Then we can apply DFS to the symmetric graph
 * obtained making edge undirected for 2-coloring
 * all connected compoenents.
 */

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
constexpr int MAX=15;

int color[MAX];
bool visited[MAX];
int v;

bool DFS(int node, const vector<vector<int>> & adj){
	visited[node]=true;
	for(vector<int>::const_iterator it=adj[node].begin(); it!=adj[node].end(); it++){
		if(color[*it]==color[node]) return false;
		color[*it]=1-color[node];
		if(!visited[*it] && !DFS(*it, adj)) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>v;
		vector<vector<int>> adj(v);
		for(int i=0; i<v; i++){
			for(int j=0; j<v; j++){
				// Making graph Symmetric and using adj lists
				int arc;
				cin>>arc;
				if(arc){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
			visited[i]=false;
			color[i]=-1;
		}
		bool is_bip=true;
		for(int i=0; i<v; i++){
			if(color[i]>=0) continue;
			color[i]=0;
			is_bip= is_bip && DFS(i, adj);
		}
		if(is_bip) cout<<1<<endl;
		else cout<<0<<endl;
	}			
	
	return 0;
}
