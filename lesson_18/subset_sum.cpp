/* This algorithm exploits basically the
 * same approach of 0-1 Knapsack pseudopolynomial
 * algorithm. Its time complexity is O(n^2*M) where
 * n is the length of the array and M an upper bound
 * of a[i] for each i.
 * REMARK: it has some problems with G4G evaluator
 * since it produces no output on their servers while
 * results are fine running it in a local environment.
 */
#include<bits/stdc++.h>
#define dbg(x) cerr << #x  << ": " << x << endl;
#define endl '\n'
using namespace std;
typedef long long ll;
#define W 100001
#define N 101

bool fr[W];
bool sr[W];
int a[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int sum=0;
		for(int i=0; i<n; i++){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum%2){
			cout<<"NO"<<endl;
			return 0;
		}
		sum/=2;
		for(int i=1; i<=sum; i++) fr[i]=false;
		fr[0]=true;
		for(int i=0; i<n; i++){
			for(int j=0; j<=sum; j++){
				if(a[i]<=j) sr[j]=fr[j] || fr[j-a[i]];
				else sr[j]=fr[j];
			}
			for(int i=0; i<=sum; i++) fr[i]=sr[i];
		}
		if(sr[sum]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}
