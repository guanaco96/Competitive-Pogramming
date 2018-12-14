/* This algorithm is very similar to the one I implemented
 * for solving the increaasing sequence problem, it runs in
 * O(n log(n)) time complexity and linear space complexity.
 * To make up for the absence of an uniform bound on a[i]s
 * I'm gonna sorting a[] and substitute a[i] with its position
 * in the sorted array (everything can be done in n log(n)).
 * Then I just calculate what's the longest increasing and
 * decrising subsequence ending and starting from each index and
 * take the maximum among all possible indexes.
 */

#include<bits/stdc++.h>
#define dbg(x) cerr << #x  << ": " << x << endl;
#define endl '\n'
using namespace std;
typedef long long ll;
#define N 102
// increasing fenwick tree
int ift[N];
// decreasing fenwick tree
int dft[N];
// input array
pair<int,int> a[N];
// input array concerning only with relative orders
// in order to allow fenwick usage without having uniform
// bounds on a[i].
int oa[N];
// number of increasing/decreasing sequences ending/starting from i.
int is[N];
int ds[N];

void update(int ind, int val, int* ft){
	ind++;
	while(ind<N){
		ft[ind]=max(ft[ind], val);
		ind+= ind & (-ind);
	}
}

int get(int ind, int* ft){
	ind++;
	int ans=0;
	while(ind>0){
		ans=max(ans, ft[ind]);
		ind-= ind & (-ind);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n; 
		for(int i=0; i<N; i++) ift[i]=dft[i]=0;
		for(int i=0; i<n; i++){
			cin>>a[i].first;
			a[i].second=i;
		}
		sort(a, a+n);
		int j=0;
		for(int i=0; i<n; i++){
			oa[a[i].second]=j;
			if(i<n-1 && a[i+1].first>a[i].first) j++;
		}
		for(int i=0; i<n; i++){
			is[i]=get(oa[i]-1, ift)+1;
			update(oa[i], is[i], ift);
		}
		for(int i=n-1; i>=0; i--){
			ds[i]=get(oa[i]-1, dft)+1;
			update(oa[i], ds[i], dft);
		}
		int ans=0;
		for(int i=0; i<n; i++) if(ans<is[i]+ds[i]-1) ans=is[i]+ds[i]-1;
		cout<<ans<<endl;
	}	
	
	return 0;
}
