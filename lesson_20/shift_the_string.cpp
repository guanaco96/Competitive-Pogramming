/* This algorithm combines KMP algorithm for patter
 * searching and binary search to find the maximum length k
 * of the prefix A[0..k-1] that is a substring of B.
 * Then executing KMP once more we can find the minimum number
 * of shifts needed, that are j iff A[1..k-1]==B[j..k+j-1].
 * Since KMP runs in linear time and binary search executes KMP
 * log(n) time it yelds a O(n log(n)) time complexity.
 */
#include<bits/stdc++.h>
#define dbg(x) cerr << #x  << ": " << x << endl;
#define endl '\n'
using namespace std;
typedef long long ll;
#define N 1000002

int lps[N];
char a[N];
char b[N];

// sz lies in [0..n]
int isPath(int sz, int n){
	int j=0;
	int shift=0;
	while(j<n){
		int i=shift;
		while(i<sz && a[i]==b[(j+i)%n]) i++;
		if(i>=sz-1) return j;
		if(i>1) shift=lps[i-1];
		j+=i>1 ? i-lps[i-1] : 1;
	}
	return -1;
}
// binary search on the maximal A's prefix matching in B
int bin_sea(int l, int r, int n){
	if(l==r) return l;
	int mid=(l+r+1)/2;
	if(isPath(mid, n)>=0) return bin_sea(mid, r, n);
	else return bin_sea(l, mid-1, n);
}
	
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<n; i++) cin>>b[i];
	int i=1;
	int len=0;
	while(i<n){
		if(a[i]==a[len]){
			len++;
			lps[i]=len;
			i++;
			continue;
		}
		if(len==0) lps[i++]=0;
		else len=lps[len-1];
	}
	cout<<isPath(bin_sea(0, n, n), n)<<endl;
	
	return 0;
}
