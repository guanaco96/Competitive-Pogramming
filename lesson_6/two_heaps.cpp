/* The key idea of this algorithm, running in linear time,
 * is that the number of different 4-digit numbers
 * depends only on the number of elements having frequency
 * one and two. The criterion then is to split those elements
 * in equal parts between our heaps, that can be made greedily
 * in linear time.
 */

#include<bits/stdc++.h>
using namespace std;

int freq[100];
pair<int,int> heap[100];

int main(){
	int n;
	cin>>n;
	vector<int> v(2*n);
	for(int i=0; i<2*n; i++){
		cin>>v[i];
		freq[v[i]]++;
	}
	int g1=0;
	int g2=0;
	int b1=0;
	int b2=0;
	for(int i=0; i<100; i++){
		if(freq[i]==1){
			if(g1<g2){
				heap[i].first++;
				g1++;
			}else{
				heap[i].second++;
				g2++;
			}
		}
		if(freq[i]>=2){
			heap[i].first=heap[i].second=1;
			g1++;
			g2++;
		}
		if(freq[i]>2){
			freq[i]=freq[i]-2;
			while(freq[i]-->0){
				if(b1<=b2){
					heap[i].first++;
					b1++;
				}else{
					heap[i].second++;
					b2++;
				}
			}
		}
	}
	cout<<g1*g2<<endl;
	for(int i=0; i<2*n; i++){
		if(heap[v[i]].first>0){
			cout<<"1"<<" ";
			heap[v[i]].first--;
		}else cout<<"2"<<" ";
	}			
	
	return 0;
}
