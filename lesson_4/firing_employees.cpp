/* This algorithm consist in two parts: a preprocessing that in 
 * O(n^(3/2)) time complexity fill a boolean tab revealing whether
 * a number in the range [0,2n-1] is a prime or not, and a second
 * part in which number of seniors (i.e. sn vector) are calculated
 * in linear time.
 */
#include<bits/stdc++.h>

using namespace std;

bool *isPrime;

void isPrime_preprocessing(int n){
	isPrime=new bool[n];
	isPrime[0]=isPrime[1]=false;
	list<int> primes;
	for(int i=2; i<n; i++){
		isPrime[i]=true;
		for(list<int>::iterator it=primes.begin(); it!=primes.end() && (*it)*(*it)<=i; it++){
			if(i%*it==0) isPrime[i]=false;
		}
		if(isPrime[i]) primes.push_back(i);
	}
}

int main(){
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int n;
		cin>>n;
		isPrime_preprocessing(2*n);
		vector<int> immediate(n+1);
		for(int j=1; j<n+1; j++) cin>>immediate[j];
		vector<int> sn(n+1,-2);
		sn[0]=-1;
		for(int j=0; j<n+1; j++){
			stack<int> met;
			int curr=j;
			while(sn[curr]<-1){
				met.push(curr);
				curr=immediate[curr];
			}
			int val=sn[curr];
			while(!met.empty()){
				sn[met.top()]=++val;
				met.pop();
			}
		}
		int blacks=0;
		for(int j=1; j<n+1; j++) if(isPrime[j+sn[j]] && sn[j]!=0) blacks++;
		cout<<blacks<<endl;
	}
	
return 0;
}
