/* This greedy algorithm provably does the job.
 * It basically scans the arry once exploiting
 * the nx[] array containing the furthest position
 * reachable from each position and applying the 
 * greedy strategy that always choose to reach the
 * index i maximizing nx[i].
 */
#include<bits/stdc++.h>
#define dbg(x) cerr << #x  << ": " << x << endl;
#define endl '\n'
using namespace std;
typedef long long ll;
#define N 101

int a[N];
int nx[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a[i];
			nx[i]=a[i]+i;
		}
		int jump=1;
		int l=0;
		int r=0;
		while(nx[l]<n-1){
			int st=r+1;
			int en=nx[l];
			for(int i=st; i<=en; i++) if(nx[i]>nx[l]) l=i;
			r=en;
			if(en==nx[l]){
				cout<<-1<<endl;
				return 0;
			}
			jump++;
		}
		cout<<jump<<endl;
	}
			
	return 0;
}
