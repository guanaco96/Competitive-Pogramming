/* This algorithm belongs to greedy paradigm. Once sorted
 * the weight vector so as it is decreasing we are picking 
 * the strongest team for which members are not coupled yet.
 */
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,pair<int,int>> triple;
struct compare{
	bool operator()(const triple& a, const triple& b){
		return a.first>b.first;
	}
};

int main(){
	int n;
	cin>>n;
	int x;
	vector<triple> w; 
	for(int i=0; i<2*n; i++) for(int j=0; j<i; j++){
		cin>>x;
		w.push_back(make_pair(x, make_pair(i,j)));
	}
	vector<int> pp(2*n, -1);
	sort(w.begin(), w.end(), compare());
	for(vector<triple>::iterator it=w.begin(); it!=w.end(); it++){
		int f=it->second.first;
		int s=it->second.second;
		if(pp[f]<0 && pp[s]<0){
			pp[f]=s;
			pp[s]=f;
		}
	}
	for(vector<int>::iterator it=pp.begin(); it!=pp.end(); it++) cout<<*it+1<<" ";
	cout<<endl;	
	
return 0;
}
