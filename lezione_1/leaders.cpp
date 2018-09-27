/* this piece of software read testcases one after another and
 * then check in linear time if any of the element, starting
 * form right, is bigger than the maximum element met so far.
 */
#include<bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin>>T;
	
	for(int i=0; i<T; i++){
		int n;
		cin>>n;
		vector<int> v(n);
		for(int j=0; j<n; j++) cin>>v[j];
		int max=v[n-1];
		for(int j=n-1; j>=0; j--) {
			if(v[j]>=max) cout<<(max=v[j])<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
