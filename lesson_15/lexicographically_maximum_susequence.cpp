/* This greedy algorithm has time complexity
 * of O(26*n) because it scans the input string
 * once for each possible lowercase letter choosing 
 * greedily the first letter being maximal in the residual
 * string.
 */
#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define endl "\n"
using namespace std;
typedef long long ll;

deque<char> solve(string::iterator ib, string::iterator ie, char max){
	deque<char> d;
	if(max<'a') return d;
	for(string::iterator it=ib; it!=ie; it++){
		if(*it==max){
			d=solve(it+1, ie, max);
			d.push_front(*it);
			return d;
		}
	}
	return solve(ib, ie, max-1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	deque<char> d=solve(s.begin(), s.end(), 'z');	
	for(deque<char>::iterator it=d.begin(); it!=d.end(); it++) cout<<*it;
	cout<<endl;
	
	return 0;
}
