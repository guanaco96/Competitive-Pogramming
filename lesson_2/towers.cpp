/* This algorithm take notes of the number of l_i met
 * so far for each l_i in [0, 1000] using a vector of
 * frequencies, resulting in linear time complexity.
 */
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(1001, 0);
	int x;
	for(int i=0; i<n; i++){
		cin>>x;
		v[x]++;
	}
	int height=0;
	int towers=0;
	for(vector<int>::iterator it=v.begin(); it!=v.end(); it++){
		if(*it>0) towers++;
		if(*it>height) height=*it;
	}
	cout<<height<<" "<<towers<<endl;
	
return 0;
}
