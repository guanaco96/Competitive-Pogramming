/* This algorithm check which side has for sure a wall tall enough
 * on its opposite side and then proceeds in the obvious greedy 
 * way until it reaches that wall.
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	for(int j=0; j<T; j++){
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0; i<n; i++) cin>>v[i];
		vector<int>::iterator ib, ie;
		ib=v.begin();
		ie=v.end();
		ie--;
		int water=0;
		while(ib!=ie){
			vector<int>::iterator it;
			if(*ib<*ie){
				it=ib;
				while(*it<=*ib) water+=*ib-*(it++);
				ib=it;
			}else{
				it=ie;
				while(*it<=*ie && it!=ib) water+=*ie-*(it--);
				ie=it;
			}
		}
		cout<<water<<endl;	
	}
	
	return 0;
}


