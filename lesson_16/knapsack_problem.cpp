/* This algorithm uses dynamic programming to
 * solve integer Knapsack problem in pseudo polynomial
 * time, more precisely it uses O(w) space and O(n*w) time
 * where w is the total weight and n the number of items 
 * (both expressed with log(w) bits). The subproblems we exploited
 * are just instances of integer Knapsack having w'=1..w and n'=1..n.
 */ 

#include<bits/stdc++.h>
#define dbg(x) cerr << #x  << ": " << x << endl;
#define endl '\n'
using namespace std;
typedef long long ll;
#define N 102

int fr[N];
int sr[N];
int vl[N];
int wt[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		int w;
		cin>>n>>w;
		for(int i=0; i<n; i++) cin>>vl[i];
		for(int i=0; i<n; i++) cin>>wt[i];
		for(int i=0; i<N; i++) fr[i]=0;
		for(int i=0; i<n; i++){
			for(int j=1; j<=w; j++){
				if(j>=wt[i]) sr[j]=max(fr[j], fr[j-wt[i]]+vl[i]);
				else sr[j]=fr[j];
			}
			for(int j=0; j<=w; j++) fr[j]=sr[j];			
		}
		cout<<sr[w]<<endl;
	}
	
	return 0;
}
