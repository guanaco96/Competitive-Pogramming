/* This algorithm sorts an array containing
 * cities' radiuses squared and population
 * by lexicographic order. Then it greedily
 * calculates the minimum radious needed to
 * accomplish our goal.
 */

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long int ll;
#define MIL 1000000


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,s;
	cin>>n>>s;
	vector<pair<int,int>> c(n);
	for(int i=0; i<n; i++){
		int x,y,k;
		cin>>x>>y>>k;
		c[i].first=x*x+y*y;
		c[i].second=k;
	}
	sort(c.begin(),c.end());
	int i=0;
	while(i<n && s<MIL) s+=c[i++].second;
	cout.precision(10);
	if(s<MIL) cout<<-1<<endl;
	else cout<<(double)sqrt(c[i-1].first)<<endl;
	
	return 0;
}
