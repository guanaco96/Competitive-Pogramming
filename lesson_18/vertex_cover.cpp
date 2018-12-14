/* This algorithm is greedy, it exploits the fact that 
 * for each leaf exists an optimal solution that doesn't 
 * contain that leaf. So what we need to do is to "update
 * our tree and iterate" this ends up to be merely a DFS
 * in which we have to remember not only how many nodes should 
 * we have painted in the subtrees but even was it necessary to
 * paint the root or not. At the end of the day we obtain linear 
 * time complexity.
 */
#include<bits/stdc++.h>
#define dbg(x) cerr << #x  << ": " << x << endl;
#define endl '\n'
using namespace std;
typedef long long ll;
#define N 1000001

bool seen[N];

// DFS returns a pair (#vertex painted, isRootPainted)
pair<int,bool> DFS(int nd, const vector<vector<int>> &adj){
	seen[nd]=true;
	bool isRP=true;
	int sum=0;
	for(auto it=adj[nd].begin(); it!=adj[nd].end(); it++){
		if(seen[*it]) continue;
		auto tmp=DFS(*it, adj);
		sum+=tmp.first;
		isRP= isRP && tmp.second;
	}
	isRP=!isRP;
	if(isRP) sum++;
	return make_pair(sum, isRP);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<vector<int>> adj(n+1);
	for(int i=0; i<n-1; i++){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout<<DFS(1, adj).first<<endl;
	
	return 0;
}
