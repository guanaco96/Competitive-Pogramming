/* This greedy algorithm performs first
 * the minimal set of moves involving the
 * leftmost nonzero number.
 */
#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define endl "\n"
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	ll off=0;
	ll ctr=0;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		ctr+=abs(x+off);
		off=-x;
	}
	cout<<ctr<<endl;		
		
	return 0;
}
