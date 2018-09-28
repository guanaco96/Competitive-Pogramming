/* This algorithm scan the input once and fill a boolean tab.
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	for(int j=0; j<T; j++){
		int n;
		cin>>n;
		bool tab[n]={false};
		for(int i=0; i<n-1; i++){
			int x;
			cin>>x;
			tab[x-1]=true;
		}
		int miss;
		for(int i=0; i<n; i++) if(!tab[i]) miss=i+1;
		cout<<miss<<endl;
	}
	
	return 0;
}
