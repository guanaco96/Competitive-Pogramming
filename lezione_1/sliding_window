/* This algorithm uses STL balanced BST to keep current
 * k-sized array ordered paying O(log(n)) for each insertion
 * or deletion. To keep track of the numbers to erase from 
 * the AVL I used a list whose operations cost us just O(1).
 */
#include<bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int n;
		cin>>n;
		int k;
		cin>>k;
		multiset<int> s;
		list<int> l;
		multiset<int>::iterator it;
		for(int j=0; j<k; j++){
			int x;
			cin>>x;
			l.push_back(x);
			s.insert(x);
		}
		cout<<*s.rbegin()<<" ";
		for(int j=k; j<n; j++){
			int x;
			cin>>x;
			s.erase(s.find(l.front()));
			l.pop_front(); 
			l.push_back(x);
			s.insert(x);
			cout<<*s.rbegin()<<" ";
		}
		cout<<endl;		
	}
	
return 0;
}
