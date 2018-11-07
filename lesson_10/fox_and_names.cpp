/* This algorithm performs a DFS to find direted
 * cycles (if any) in the directed graph induced
 * on lowercase character by lexicographical order.
 * If graph is a DAG algorith produces a topological
 * sorting of ['a'..'z']. The whole algorithm
 * takes linear (in number of strings) time to be perfomed.
 */

#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;

bool adj[26][26];
int seen[26];

bool DFS(int node, deque<char> &sorted){
	seen[node]=-1; //currently in the stack
	for(int i=0; i<26; i++){
		if(!adj[node][i]) continue;
		if(seen[i]<0) return false;
		if(seen[i]==0 && !DFS(i, sorted)) return false;
	}
	seen[node]=1;
	sorted.push_front(node);
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n; 
	vector<string> v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	for(int i=0; i<n-1; i++){
		string s1=v[i];
		string s2=v[i+1];
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		while(!s1.empty() && !s2.empty() && s1.back()==s2.back()){
			s1.pop_back();
			s2.pop_back();
		}
		// preventing acceptance of ordering in which str1@str2<str1 
		if(!s1.empty() && s2.empty()){
			cout<<"Impossible"<<endl;
			return 0;
		}
		if(!s1.empty() && !s2.empty()) adj[s1.back()-'a'][s2.back()-'a']=true;
	}
	deque<char> sorted;
	bool is_sortable=true;
	for(int i=0; i<26; i++) if(!seen[i]) is_sortable=is_sortable && DFS(i, sorted);
	if(is_sortable) for(deque<char>::iterator it=sorted.begin(); it!=sorted.end(); it++) cout<<(char)(*it+'a');
	else cout<<"Impossible";
	cout<<endl;
	
	return 0;
}
