/* This algorithm is defined recursively. It is like a merge
 * sort that taking how many elements belonging to
 * the upper half of the array are overcome by elements belonging
 * to the lower half into account while merging.
 */
#include<bits/stdc++.h>

using namespace std;

long inversions(vector<long>& v){
	long n=v.size();
	if(n<=1) return 0;
	long counter=0;
	long upper=0;
	vector<long> l(v.begin(), v.begin()+n/2);
	vector<long> u(v.begin()+n/2, v.end());
	counter+=inversions(l);
	counter+=inversions(u);
	vector<long>::iterator il=l.begin();
	vector<long>::iterator iu=u.begin();
	vector<long>::iterator iv=v.begin();
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
	long T;
	cin>>T;
	for(long i=0; i<T; i++){
		long n;
		cin>>n;
		vector<long> v(n);
		for(long j=0; j<n; j++) cin>>v[j];
		cout<<inversions(v)<<endl;
	}
	
return 0;
}
