/* This algorithm builds a centroid decomposition
 * of the original tree and for each node keeps
 * an associative array linking any of its descendents to
 * its distance to that node using O(n log(n)) space.
 * Moreover for each node we store the distance of the closest
 * red descendent. Then we can perform paint and get queries
 * traversing the height of the centroid tree just once,
 * obtaining O(log(n)) time complexity for any query.
 */

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
#define N 100002

struct node{
	int cl; //closest red
	int ft; //father
	map<int,int> dist;
	node(): cl(N), ft(-1){}
};

node ct[N];
vector<vector<int>> adj;
bool added[N];
bool seen[N];

int DFS(int nd, map<int,pair<int,int>> &m){
	int acc=1;
	seen[nd]=true;
	for(vector<int>::iterator it=adj[nd].begin(); it!=adj[nd].end(); it++){
		if(seen[*it] || added[*it]) continue;
		int tmp=DFS(*it, m);
		acc+=tmp;
		m.insert(make_pair(*it,make_pair(nd, tmp)));
	}
	return acc;
}

int find_centroid(int nd, int sz, map<int,pair<int,int>> &m){
	m.insert(make_pair(nd,make_pair(nd, DFS(nd, m))));
	for(map<int,pair<int,int>>::iterator it=m.begin(); it!=m.end(); it++){
		seen[it->first]=false;
	}
	bool isCentroid=false;
	int curr=nd;
	while(!isCentroid){
		int ft=m[curr].first;
		isCentroid=true;
		for(vector<int>::iterator it=adj[curr].begin(); it!=adj[curr].end(); it++){
			if(*it==ft) continue;
			if(m[*it].second>sz/2){
				isCentroid=false;
				curr=*it;
				break;
			}
		}
	}
	return curr;
}

void dist_DFS(int nd, int h, map<int,int> &dist){
	seen[nd]=true;
	dist.insert(make_pair(nd, h));
	for(vector<int>::iterator it=adj[nd].begin(); it!=adj[nd].end(); it++){
		if(seen[*it] || added[*it]) continue;
		dist_DFS(*it, h+1, dist);
	}
}	

void build(int nd, int ft, map<int,pair<int,int>> m){
	added[nd]=true;
	ct[nd].ft=ft;
	dist_DFS(nd, 0, ct[nd].dist);
	for(map<int,int>::iterator it=ct[nd].dist.begin(); it!=ct[nd].dist.end(); it++){
		seen[it->first]=false;
	}
	for(vector<int>::iterator it=adj[nd].begin(); it!=adj[nd].end(); it++){
		if(added[*it]) continue;
		int sz=m[*it].second;
		map<int,pair<int,int>> mm;
		int root=find_centroid(*it, sz, mm);
		build(root, nd, mm);
	}
}			

void update(int nd){
	int curr=nd;
	while(curr>=0){
		ct[curr].cl=min(ct[curr].cl, ct[curr].dist[nd]);
		curr=ct[curr].ft;
	}
}

int get(int nd){
	int acc=N;
	int curr=nd;
	while(curr>=0){
		acc=min(ct[curr].dist[nd]+ct[curr].cl, acc);
		curr=ct[curr].ft;
	}
	return acc;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin>>n>>m;
	adj=vector<vector<int>>(n+1);
	for(int i=0; i<n-1; i++){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	map<int,pair<int,int>> mm;
	int root=find_centroid(1, n, mm);
	build(root, -1, mm);
	for(int i=1; i<=7; i++){
		for(map<int,int>::iterator it=ct[i].dist.begin(); it!=ct[i].dist.end(); it++){
		}
	}
	//paint first node
	update(1);
	for(int i=0; i<m; i++){
		int t, v;
		cin>>t>>v;
		switch(t){
			case 1: update(v);
					break;
			case 2: cout<<get(v)<<endl;
					break;
		}
	}	
	
	return 0;
}
