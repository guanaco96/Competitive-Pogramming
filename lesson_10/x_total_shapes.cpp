/* This algorithm runs in O(m*n).
 * It counts the number of connected components in our graph
 * (there's an arc between any adjacent Xes).
 * Using the union-find data structure implementing
 * path halving optimization, we obtain constant time
 * for union and find operations.
 */

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
constexpr int MAX=50;

char tab[MAX][MAX];
pair<int,int> ft[MAX][MAX];
bool seen[MAX][MAX];

pair<int,int> find(pair<int,int> p){
	while(ft[p.first][p.second]!=p){
		pair<int,int> tmp=p;
		p=ft[p.first][p.second];
		ft[tmp.first][tmp.second]=ft[p.first][p.second];
	}
	return p;
}

void uni(pair<int,int> p1, pair<int,int> p2){
	p1=find(p1);
	p2=find(p2);
	ft[p1.first][p1.second]=p2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n, m;
		cin>>n>>m;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>tab[i][j];
				ft[i][j]=make_pair(i,j);
				seen[i][j]=false;
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(tab[i][j]!='X') continue;
				if(i>0 && tab[i-1][j]=='X') uni(make_pair(i,j), make_pair(i-1,j));
				if(j<m-1 && tab[i][j+1]=='X') uni(make_pair(i,j), make_pair(i,j+1));
				if(i<n-1 && tab[i+1][j]=='X') uni(make_pair(i,j), make_pair(i+1,j));
				if(j>0 && tab[i][j-1]=='X') uni(make_pair(i,j), make_pair(i,j-1));
			}
		}
		int comp=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(tab[i][j]!='X') continue;
				pair<int,int> p=find(make_pair(i,j));
				if(seen[p.first][p.second]) continue;
				seen[p.first][p.second]=true;
				comp++;
			}
		}
		cout<<comp<<endl;	
	}
	
	return 0;
}
