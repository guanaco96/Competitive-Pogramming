/* This algorithm is defined recursively. It is like a merge
 * sort that taking how many elements belonging to
 * the upper half of the array are overcome by elements belonging
 * to the lower half into account while merging.
 */
#include<bits/stdc++.h>

using namespace std;

int inversions(vector<int>& v){
	int n=v.size();
	if(n<=1) return 0;
	int counter=0;
	int upper=0;
	vector<int> l(v.begin(), v.begin()+n/2);
	vector<int> u(v.begin()+n/2, v.end());
	counter+=inversions(l);
	counter+=inversions(u);
	vector<int>::iterator il=l.begin();
	vector<int>::iterator iu=u.begin();
	vector<int>::iterator iv=v.begin();
	while(il!=l.end() || iu!=u.end()){
		while(il!=l.end() && (iu==u.end() || *il<=*iu)){
			*(iv++)=*(il++);
			counter+=upper;
		}
		while(iu!=u.end() && (il==l.end() || *iu<*il)){
			*(iv++)=*(iu++);
			upper++;
		}
	}
	return counter;
}

int main(){
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int n;
		cin>>n;
		vector<int> v(n);
		for(int j=0; j<n; j++) cin>>v[j];
		cout<<inversions(v)<<endl;
	}
	
return 0;
}
