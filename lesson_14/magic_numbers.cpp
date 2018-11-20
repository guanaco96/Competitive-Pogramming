/* This algorithm proceeds greedily
 * checking if the number of four after
 * each one is no more than 2, maintaining 
 * a counter of fours seen till the last one occurred.
 */
#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define endl "\n"
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	deque<int> d;
	while(n>0){
		d.push_front(n%10);
		n/=10;
	}
	bool isMagic=true;
	int four=2;
	for(deque<int>::iterator c=d.begin(); c!=d.end(); c++){
		if(*c!=1 && *c!=4) isMagic=false;
		if(*c==1) four=0;
		else if(four++==2) isMagic=false;
	}
	if(isMagic) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;		
	
	return 0;
}
