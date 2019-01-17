/* This is an improved solution of "shifting the stirng"
 * problem, basically it sticks to a KMP-like algorithm
 * exploiting lps to calculate the maximal prefix of A
 * being a substring of B. It improves my previous solution
 * that was quite similar but for no evident reason used even
 * binary search charging time complexity with an additional log(n).
 */
 
#include<bits/stdc++.h>
#define dbg(x) cerr << #x  << ": " << x << endl;
#define endl '\n'
using namespace std;
typedef long long ll;

const int N = 1000001;
int lps[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	
	int l = 0;
	int i = 1;
	while(i < n) {
		if(a[i] == a[l]) {
			l++;
			i++;
			lps[i] = l;
			continue;
		}
		if(l > 0) l = lps[l];
		else i++;
	}
	
	int shift = 0;
	int mx = 0;
	int argmx = 0;
	l = 0;
	while(l < n && shift < n) {
		if(a[l] == b[(l + shift) % n]) {
			l++;
			if(mx < l){
				mx = l;
				argmx = shift;
			}
			continue;
		}
		if(l > 0) {
			shift += l - lps[l];
			l = lps[l];
		}
		else shift++;
	}
	
	cout << argmx << endl;
	
	
	return 0;
}
