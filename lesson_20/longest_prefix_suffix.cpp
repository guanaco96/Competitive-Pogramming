/* This algorithm find the lps (longest prefix suffix) of
 * the given string s in linear time as follows:
 * given that we have coputed lps[1..k-1] we can obtain
 * lps[k] trying to increment lps[k-1] if last characters
 * match then we're fine, otherwise we've to try the maximum
 * length prefix of s[0..lps[k-1]-1] that has chances to match
 * with a suffix of s[0..lps[k-1]-1] that is lps[lps[k-1]-1] long.
 * We iterate this till we find the following character matching or 
 * we've reduced ourselves to a prefix of length 0 and then we set lps[k]=0.
 */
#include<bits/stdc++.h>
#define dbg(x) cerr << #x  << ": " << x << endl;
#define endl '\n'
using namespace std;
typedef long long ll;

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
		// lps associates i->lps of s[0..i]
		vector<int> lps(n);
		int len=0;
		int i=1;
		while(i<n){
			if(s[len]==s[i]){
				len++;
				lps[i]=len;
				i++;
				continue;
			}			
			if(len==0){
				i++;
				lps[i]=0;
			}
			else len=lps[len-1];
		}
		cout<<lps[n-1]<<endl;
	}
	
	return 0;
}
