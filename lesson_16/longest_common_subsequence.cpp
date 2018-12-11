/* This algorithm spends O(n^2) time and
 * O(n) space to solve the largest common
 * subsequence problem. It makes use of the
 * dynamic programming paradigm where the
 * subproblems are the number of LCS of s1[0..i]
 * and s2[0..j] for i<=n && j<=m.
 */
#include<bits/stdc++.h>
#define dbg(x) cerr << #x  << ": " << x << endl;
#define endl '\n'
using namespace std;
typedef long long ll;
#define N 101

int fr[N];
int sr[N];
char s1[N];
char s2[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n, m;
		cin>>n>>m;
		for(int i=1; i<=n; i++) cin>>s1[i];
		for(int i=1; i<=m; i++) cin>>s2[i];
		for(int i=0; i<N; i++) fr[i]=0;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(s1[i]==s2[j]) sr[j]=1+fr[j-1];
				else sr[j]=max(fr[j], sr[j-1]);
			}
			for(int k=1; k<=m; k++) fr[k]=sr[k];
		}
		cout<<sr[m]<<endl;
	}				
	
	return 0;
}
