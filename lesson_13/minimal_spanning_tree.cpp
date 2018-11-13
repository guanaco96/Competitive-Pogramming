/* This is a standard implementation
 * of Kruscal algorithm using a forest
 * data structure to support union-
 * find queries.
 */

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
constexpr int N=10001;

struct edge{
	int st;
	int en;
	int we;
};

bool comp(const edge &e1, const edge &e2){
		return e1.we<e2.we;
}

int ft[N];

int find(int x){
	if(ft[x]!=x) ft[x]=find(ft[x]);
	return ft[x];
}

void uni(int x, int y){
	x=find(x);
	y=find(y);
	ft[x]=y;
}	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin>>n>>m;
	vector<edge> ed(m);
	for(int i=0; i<m; i++) cin>>ed[i].st>>ed[i].en>>ed[i].we;
	sort(ed.begin(), ed.end(), comp);
	for(int i=0; i<n; i++) ft[i]=i;
	ll sum=0;
	for(vector<edge>::iterator it=ed.begin(); it!=ed.end(); it++){
		if(find(it->st)==find(it->en)) continue;
		uni(it->st, it->en);
		sum+=it->we;
	}
	cout<<sum<<endl;	
	
	return 0;
}
