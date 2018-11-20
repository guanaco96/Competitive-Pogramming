/* This greedy algorithm counts how many
 * consecutive digits are equal and how many
 * are different, then outputs #different
 * plus max(#equals, 2) that can be proven
 * being the optimal strategy for this game.
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
	char x, y;
	int ctr=0;
	int eq=0;
	cin>>x;
	for(int i=1; i<n; i++){
		cin>>y;
		if(x!=y) ctr++;
		else eq++;
		x=y;
	}
	if(eq>=2) ctr+=2;
	if(eq==1) ctr++;
	ctr++;
	cout<<ctr<<endl;	
	
	return 0;
}
