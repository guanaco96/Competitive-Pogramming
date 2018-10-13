/* This algorithm performs a preprocessing computing
 * a vector prefix_sum such that prefix_sum[i] contains
 * the number of j<i such that s[j]=s[j+1].
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	vector<int> prefix_sum(s.size());
	prefix_sum[0]=0;
	for(int i=0; i<(int)s.size()-1; i++){
		prefix_sum[i+1]=prefix_sum[i];
		if(s[i]==s[i+1]) prefix_sum[i+1]++;
	}
	int m;
	cin>>m;
	for(int i=0; i<m; i++){
		int l, r;
		cin>>l>>r;
		cout<<prefix_sum[r-1]-prefix_sum[l-1]<<endl;
	}
	
	return 0;
}
