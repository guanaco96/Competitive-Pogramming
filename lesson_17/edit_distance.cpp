/* Considering that all available operations
 * commutate pairwise and that inserting an element
 * is equivalent to deleting an element of the other 
 * string then we can easily set up a dynamic programming
 * algorithm that solves our problem in O(n*m) time complexity.
 * REMARK: given the DP law we could have optimized this
 * algorithm to run in O(m+n) space but I found easier to 
 * write it using recursion so that I wasted some space using
 * O(n*m) space too.
 */

#include<bits/stdc++.h>
#define dbg(x) cerr << #x  << ": " << x << endl;
#define endl '\n'
using namespace std;
typedef long long ll;
#define N 102

char s1[N];
char s2[N];
int tab[N][N];

// Recursive function building the tab
int get(int x, int y){
	if(tab[x][y]>=0) return tab[x][y];
	if(s1[x]==s2[y]) return tab[x][y]=get(x-1, y-1);
	tab[x][y]=1+min(min(get(x-1, y), get(x, y-1)), get(x-1, y-1));
	return tab[x][y];
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
		// Set up boundary conditions for tab
		for(int i=0; i<=n; i++) for(int j=0; j<=m; j++) tab[i][j]=-1;
		for(int i=0; i<=n; i++) tab[i][0]=i;
		for(int i=0; i<=m; i++) tab[0][i]=i;
		// Read input stirngs
		for(int i=1; i<=n; i++) cin>>s1[i];
		for(int i=1; i<=m; i++) cin>>s2[i];
		cout<<get(n, m)<<endl;
	}
		
		
	return 0;
}
