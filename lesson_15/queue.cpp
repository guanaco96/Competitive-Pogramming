/* This algorithm is greedy. It sorts people by increasing a_i.
 * That will be the queue's order if there's a feasible one.
 * In order to compute all the heights we insert, following this order,
 * in an array called hor (i.e. height order) people so that
 * person i would have exactly a_i people inserted yet on his right.
 * If it's not feasible then we can prove that there's no order
 * satisfying the desired propriety. Then we only have to turn hor
 * into real heghts (array h). All this stuff is made in O(n^2) time
 * complexity due to expensive insertions in the mid of vectors.
 */

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define endl "\n"
using namespace std;
typedef long long ll;
#define N 30001

string s[N];
pair<int,int> a[N];
int h[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>s[i]>>a[i].first;
		a[i].second=i;
	}
	sort(a, a+n);
	vector<int> hor; //height order
	for(int i=0; i<n; i++){
		if(a[i].first>(int)hor.size()){
			cout<<-1<<endl;
			return 0;
		}
		hor.insert(hor.end()-a[i].first, i);
	}
	for(int i=0; i<n; i++) h[hor[i]]=i+1;
	for(int i=0; i<n; i++) cout<<s[a[i].second]<<" "<<h[i]<<endl;
	
	
	return 0;
}
