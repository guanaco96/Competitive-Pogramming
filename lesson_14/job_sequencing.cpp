/* This is an implementation of the greedy
 * algorithm for job sequencing problem.
 * It sorts tasks by increasing ending time
 * and then pick up the first one not colliding
 * with already taken ones.
 */

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
#define N 100

struct mt{
	int s;
	int f;
	int ind;
};

bool comp(const mt &m1, const mt &m2){ return m1.f<m2.f;}

mt sf[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=0; i<n; i++) cin>>sf[i].s;
		for(int i=0; i<n; i++) cin>>sf[i].f;
		for(int i=0; i<n; i++) sf[i].ind=i+1;
		sort(sf, sf+n, comp);
		vector<int> taken;
		int lf=0;
		for(int i=0; i<n; i++){
			if(sf[i].s<lf) continue;
			taken.push_back(sf[i].ind);
			lf=sf[i].f;
		}
		for(vector<int>::iterator it=taken.begin(); it!=taken.end(); it++){
			cout<<*it<<" ";
		}
		cout<<endl;
	}		
	
	return 0;
}
