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
constexpr int N=100001;

int color[N];
vector<vector<int>> tree;
vector<pair<int,int>> vert_to_sub;

void DFS(int index, vector<int> lin){
	vert_to_sub[index].first=lin.size();
	lin.push_back(index);
	for(vector<int>::iterator it=tree[index].begin(); it!=tree[index].end(); it++){
		DFS(*it, lin);
	}
	vert_to_sub[index].second=lin.size()-1;
}

ll trans(int os, int oe, int ns, int ne){
	ll tot=0;
	if(os>ns){
		for(int i=ns; i<os; i++){
			tot+=a[i]*(2*val[a[i]]+1);
			val[a[i]]++;
		}
	}
	else{
		for(int i=os; i<ns; i++){
			val[a[i]]--;
			tot-=a[i]*(2*val[a[i]]+1);			
		}
	}
	for(int i=oe; i<ne; i++){
		tot+=a[i]*(2*val[a[i]]+1);
		val[a[i]]++;
	}
	return tot;
}		

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin>>n>>m;
	for(int i=0; i<n; i++) cin>>color[i];
	tree=vector<vector<int>>(n+1);
	for(int i=0; i<n-1; i++){
		int a, b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	vert_to_sub=vector<pair<int,int>>(n);
	vector<int> lin;
	DFS(1, lin);
	
	
	
	return 0;
}
