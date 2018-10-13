/* This algorithm calculates the total time needed
 * to eat all the bars and count how many bars alice
 * can eat starting from the left and checking for each
 * bar if bob has started to eat the following yet.
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> time(n);
	int tot=0;
	for(int i=0; i<n; i++){
		cin>>time[i];
		tot+=time[i];
	}
	int curr=0;
	int barN=0;
	while(2*curr+time[barN]<=tot) curr+=time[barN++];
	cout<<barN<<" "<<n-barN<<endl;
	
	return 0;
}
