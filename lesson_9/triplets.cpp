/* This algorithm runs in O(n log(n)).
 * It scans the array keeping track of the number of
 * elements less or equal to k for every k in [1,n)
 * standing both on the left and right of the current
 * element being scanned. We can achieve log(n) time for
 * both update and lookup operations thanks to Fenwick tree.
 */

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;

int n;
vector<int> bitL, bitR;

void update(vector<int> &bit, int index, int val){
	index++;
	while(index<n+1){
		bit[index]+=val;
		index+= index & (-index);
	}
}

int get(const vector<int> &bit, int index){
	index++;
	int sum=0;
	while(index>0){
		sum+=bit[index];
		index-=index & (-index);
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	vector<int> A(n);
	// Let's note that 0<A[i]<n for_each i
	bitL=vector<int>(n+1);
	bitR=vector<int>(n+1);
	for(int i=0; i<n; i++){
		cin>>A[i];
		update(bitR, A[i], 1);
	}
	ll tot=0;
	for(int i=0; i<n; i++){
		update(bitR, A[i], -1);
		tot+=get(bitL, A[i]-1)*(get(bitR, n-1)-get(bitR, A[i]));
		update(bitL, A[i], 1);
	}
	cout<<tot<<endl;	
	
	return 0;
}
