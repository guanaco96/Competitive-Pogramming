/* This algorithm runs in O(n).
 * It scans trees from left to right and
 * if it's feasible it cuts a tree making it fall on the
 * left if able and on the right otherwise.
 */
 
#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define endl "\n"
using namespace std;
typedef long long ll;
#define N 100002

int x[N];
int h[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=0; i<n; i++) cin>>x[i]>>h[i];
	x[n]=2000000002;
	int ctr=0;
	int le=-1000000001;
	for(int i=0; i<n; i++){
		if(x[i]-h[i]>le){
			le=x[i];
			ctr++;
		}
		else{
			if(x[i]+h[i]<x[i+1]){
				le=x[i]+h[i];
				ctr++;
			}
			else le=x[i];
		}
	}
	cout<<ctr<<endl; 
		
	return 0;
}
