/* This algorithm checks recursively if the array has
 * the following propriety: given A the first element,
 * being [A_1, ..., A_k] the maximal array of its consecutive
 * successor such that A_i<A for each i<=k, then any element
 * following A_k must be greater than A, the same must apply 
 * recursively to vectors [A_1, ..., A_k] & [A_k+1, ..., end].
 */
#include<bits/stdc++.h>

using namespace std;

bool isBST(vector<int>::iterator ib, vector<int>::iterator ie){
	if(ib+1==ie || ib==ie) return true;
	vector<int>::iterator it;
	for(it=ib+1; it!=ie && *it<*ib; it++);
	for(vector<int>::iterator ir=it; ir!=ie; ir++) if(*ir<=*ib) return false;
	return isBST(ib+1, it) && isBST(it, ie);	
};

int main(){
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int n;
		cin>>n;
		vector<int> v(n);
		for(int j=0; j<n; j++) cin>>v[j];
		cout<<isBST(v.begin(), v.end())<<endl;		
	}
	
return 0;
}
