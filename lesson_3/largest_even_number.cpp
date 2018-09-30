/* This algorithm behaves similarly to counting sort.
 * It sorts digits and then select the number to be printed
 * rightmost.
 */
#include<bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin>>T;
	char c;
	c=getchar();
	for(int i=0; i<T; i++){
		int digits[10]={0};
		while((c=getchar())<='9' && c>='0') digits[c-'0']++;
		int rightmost=-1;
		for(int j=0; rightmost<0 && j<10; j=j+2){
			if(digits[j]>0){
				rightmost=j;
				digits[j]--;
			}
		}
		for(int j=1; rightmost<0 && j<10; j=j+2){
			if(digits[j]>0){
				rightmost=j;
				digits[j]--;
			}
		}
		for(int j=9; j>=0; j--) for(int k=0; k<digits[j]; k++) cout<<j;
		cout<<rightmost<<endl;
	}
	
return 0;
}
