/* This algorithm stores, for each element B[i]
 * of B, the last copy query targetting i.
 * We can perform both copy and get in O(log n)
 * using a range tree.
 */ 
#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;

vector<int> tree;

void update(int val, int node, int us, int ue, int is, int ie){
	if(is>ue || ie<us) return;
	if(is>=us && ie<=ue) {
		tree[node]=val;
		return;
	}
	int mid=(is+ie)/2;
	update(val, 2*node+1, us, ue, is, mid);
	update(val, 2*node+2, us, ue, mid+1, ie);
}

int get(int node, int qn, int is, int ie){
	if(qn<is || qn>ie) return -1;
	if(qn==is && qn==ie) return tree[node];
	int mid=(is+ie)/2;
	return max(tree[node], max(get(2*node+1, qn, is, mid), get(2*node+2, qn, mid+1, ie)));
}	

struct cc{
	int x;
	int y;
	int k;
	cc(int a, int b, int c): x(a), y(b), k(c){}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin>>n>>m;
	vector<int> A(n);
	vector<int> B(n);
	for(int i=0; i<n; i++) cin>>A[i];
	for(int i=0; i<n; i++) cin>>B[i];
	vector<cc> copy;
	tree=vector<int>(n<<2, -1);
	for(int i=0; i<m; i++){
		int cs;
		cin>>cs;
		if(cs==1){
			int x, y, k;
			cin>>x>>y>>k;
			update(copy.size(), 0, y, y+k, 0, n-1);
			copy.push_back(cc(x,y,k));
		}
		if(cs==2){
			int index;
			cin>>index;
			int q=get(0, index, 0, n-1);
			if(q<0) cout<<B[index]<<endl;
			else cout<<A[copy[q].x+index-copy[q].y]<<endl;}
	}
			
	return 0;
}
