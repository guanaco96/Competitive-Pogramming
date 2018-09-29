/* This algorithm uses a stack to store indexes of elements
 * not yet matched with their minimum-index greater element
 * allowing us to complete our task in linear time.
 */
#include<bits/stdc++.h>

using namespace std;

vector<int> v, w;
stack<int> s;

void insert(int j){
	while(!s.empty() && v[j]>v[s.top()]){
		w[s.top()]=v[j];
		s.pop();
	}
	s.push(j);
}

void devoid(){
	while(!s.empty()){
		w[s.top()]=-1;
		s.pop();
	}
}
		
int main(){
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int n;
		cin>>n;
		v.resize(n);
		w.resize(n);
		for(int j=0; j<n; j++) cin>>v[j];
		for(int j=0; j<n; j++) insert(j);
		devoid();
		for(int j=0; j<n; j++) cout<<w[j]<<" ";
		cout<<endl;
	}
	
return 0;
}
