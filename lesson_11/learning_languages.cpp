/* This algorithm uses a union-find structure
 * to count the number of connected components
 * among languages used by somebody. Then it adds
 * 1 cost unit for each employee that knows no language.
 */

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;

int ft[101];
bool used[101];
bool counted[101];

int find(int node){
	while(ft[node]!=node){
		int tmp=node;
		node=ft[node];
		ft[tmp]=ft[node];
	}
	return node;
}

void uni(int n1, int n2){
	n1=find(n1);
	n2=find(n2);
	ft[n1]=n2;
}		

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0; i<101; i++) ft[i]=i;
	int n, m;
	cin>>n>>m;
	int cost=0;
	for(int i=0; i<n; i++){
		int l;
		cin>>l;
		if(l==0){
			cost++;
			continue;
		}
		int x, y;
		cin>>x;
		used[x]=true;
		l--;
		while(l--){
			cin>>y;
			used[y]=true;
			uni(x,y);
			x=y;
		}
	}
	bool is_a_comp=false;
	for(int i=0; i<101; i++){
		if(!used[i]) continue;
		int cc=find(i);
		if(counted[cc]) continue;
		counted[cc]=true;
		cost++;
		is_a_comp=true;
	}
	if(is_a_comp) cost--;
	cout<<cost<<endl;	
	
	return 0;
}
