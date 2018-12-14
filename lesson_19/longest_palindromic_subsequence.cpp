/* This algorithm uses dynamic programming ands subpreblems
 * are the maximum length subsequence within the substring
 * [i..j] of the original string. It runs in O(n^2) time and
 * O(n) space complexity.
 */

#include<bits/stdc++.h>
#define dbg(x) cerr << #x  << ": " << x << endl;
#define endl '\n'
using namespace std;
typedef long long ll;
#define N 1001

int fr[N];
int sr[N];
int tr[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int n=s.size();
		for(int i=0; i<n; i++) sr[i]=1;
		for(int i=0; i<n; i++) fr[i]=0;
		for(int i=1; i<n; i++){
			for(int j=0; i+j<n; j++){
				if(s[j]==s[j+i]) tr[j]=2+fr[j+1];
				else tr[j]=max(sr[j], sr[j+1]);
			}
			for(int i=0; i<n; i++){
				fr[i]=sr[i];
				sr[i]=tr[i];
			}
		}
		cout<<tr[0]<<endl;
	}
	
	return 0;
}
