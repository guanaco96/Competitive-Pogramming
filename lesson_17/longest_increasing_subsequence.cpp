/* This algorithm uses dynamic programming combined with
 * Fenwick trees to solve the problem in O(n log(n)) time 
 * and O(K) space complexity, where n is the length of the
 * array and K is an uniform bound on array's values.
 * The subproblems we're going to solve are the following:
 * for each x in [1..K] we store the length of the longest
 * increasing subsequence met so far (while scanning the 
 * orginal array), we can update that in log(n) thanks to 
 * Fenwick trees and once we reach the end of the array
 * the job is done taking the maximum of the whole array.
 * (Notice that Fenwick tree here is used to perform prefix
 * max queries.)
 */
#include<bits/stdc++.h>
#define dbg(x) cerr << #x  << ": " << x << endl;
#define endl '\n'
using namespace std;
typedef long long ll;
#define K 302

int ft[K];

void update(int index, int val){
	index++;
	while(index<K){
		ft[index]=max(ft[index], val);
		index+= index & (-index);
	}
}

int get(int index){
	index++;
	int ans=0;
	while(index>0){
		ans=max(ans, ft[index]);
		index-= index & (-index);
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
		for(int i=0; i<K; i++) ft[i]=0;
		int n;
		cin>>n;
		for(int i=0; i<n; i++){
			int x;
			cin>>x; 
			update(x, get(x-1)+1);
		}
		cout<<get(300)<<endl;
	}
	
	return 0;
}
